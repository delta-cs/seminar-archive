using System;
using System.Collections.Generic;
using System.Linq;

internal class Program
{
    static void Main(string[] args)
    {
        Dictionary<string, double> variables = new Dictionary<string, double>();

        int c = int.Parse(Console.ReadLine());

        List<string[]> linesSplit = new List<string[]>();
        List<int> linesNestLevels = new List<int>();

        for (int i = 0; i < c; i++)
        {
            string line = Console.ReadLine().Split("//")[0].TrimEnd();

            if (line == string.Empty)
            {
                continue;
            }

            int nestLevel = 0;
            while (line.Length > 2 && line.StartsWith("  "))
            {
                line = line.Substring(2);
                nestLevel++;
            }

            linesSplit.Add(line.Split(' '));
            linesNestLevels.Add(nestLevel);
        }

        List<double> output = new List<double>();

        bool repeating = false;
        int repeatStartLineIndex = 0;
        int nestLevelCurrent = 0;

        for (int i = 0; i < linesSplit.Count; i++)
        {
            string[] lineSplit = linesSplit[i];
            int nestLevel = linesNestLevels[i];

            if (nestLevel > nestLevelCurrent)
            {
                continue;
            }

            bool atLastLine = i >= linesSplit.Count - 1;

            if (repeating && (nestLevel < linesNestLevels[repeatStartLineIndex] + 1 || atLastLine))
            {
                repeating = false;
                i = repeatStartLineIndex - 1;
                if (!atLastLine)
                {
                    continue;
                }
            }
            else if (nestLevel < nestLevelCurrent)
            {
                nestLevelCurrent = nestLevel;
            }

            switch (lineSplit[0])
            {
                case "kdyz":
                {
                    if (lineSplit.Length < 5 || lineSplit[lineSplit.Length - 1] != "tak")
                    {
                        Console.WriteLine("error");
                        return;
                    }

                    (bool, bool) conditionResult = ConditionPass(lineSplit.Skip(1).SkipLast(1).ToArray(), variables);

                    if (!conditionResult.Item1)
                    {
                        Console.WriteLine("error");
                        return;
                    }

                    if (conditionResult.Item2)
                    {
                        nestLevelCurrent++;
                    }

                    break;
                }

                case "dokud":
                {
                    if (lineSplit.Length < 5 || lineSplit[lineSplit.Length - 1] != "tak")
                    {
                        Console.WriteLine("error");
                        return;
                    }

                    (bool, bool) conditionResult = ConditionPass(lineSplit.Skip(1).SkipLast(1).ToArray(), variables);

                    if (!conditionResult.Item1)
                    {
                        Console.WriteLine("error");
                        return;
                    }

                    if (conditionResult.Item2)
                    {
                        nestLevelCurrent++;
                        repeating = true;
                        repeatStartLineIndex = i;
                    }

                    break;
                }

                case "vypsat":
                {
                    (bool, double) expressionResult = ExpressionValue(lineSplit.Skip(1).ToArray(), variables);

                    if (!expressionResult.Item1)
                    {
                        Console.WriteLine("error");
                        return;
                    }

                    output.Add(expressionResult.Item2);
                    break;
                }

                default:
                {
                    string variableName = lineSplit[0];

                    if (char.ToLower(variableName[0]) < 'a' || char.ToLower(variableName[0]) > 'z'
                                                            || lineSplit.Length < 2 || lineSplit[1] != "je")
                    {
                        Console.WriteLine("error");
                        return;
                    }

                    switch (variableName)
                    {
                        case "je":
                        case "a":
                        case "bez":
                        case "kdyz":
                        case "tak":
                        case "rovno":
                        case "aspon":
                        case "nejvic":
                        case "nebo":
                        case "dokud":
                        case "vypsat":
                            Console.WriteLine("error");
                            return;
                    }

                    (bool, double) expressionResult = ExpressionValue(lineSplit.Skip(2).ToArray(), variables);

                    if (!expressionResult.Item1)
                    {
                        Console.WriteLine("error");
                        return;
                    }

                    variables[variableName] = expressionResult.Item2;
                    break;
                }
            }
        }

        foreach (double line in output)
        {
            Console.WriteLine(line);
        }
    }

    static (bool, double) ExpressionValue(string[] lineSplit, Dictionary<string, double> variables)
    {
        if (lineSplit.Length % 2 != 1)
        {
            return (false, 0);
        }

        bool expressionAdd = true;
        double expressionValue = 0;

        for (int w = 0; w < lineSplit.Length; w++)
        {
            if (w % 2 == 0)
            {
                double value;
                if (!double.TryParse(lineSplit[w], out value) && !variables.TryGetValue(lineSplit[w], out value))
                {
                    return (false, 0);
                }

                expressionValue += expressionAdd ? value : -value;
            }
            else
            {
                switch (lineSplit[w])
                {
                    case "a":
                        expressionAdd = true;
                        break;
                    case "bez":
                        expressionAdd = false;
                        break;
                    default:
                        return (false, 0);
                }
            }
        }

        return (true, expressionValue);
    }

    static (bool, bool) ConditionPass(string[] lineSplit, Dictionary<string, double> variables)
    {
        List<int> orIndexes = new List<int>();
        orIndexes.Add(-1);
        for (int i = 0; i < lineSplit.Length; i++)
        {
            if (lineSplit[i] == "nebo")
            {
                orIndexes.Add(i);
            }
        }

        orIndexes.Add(lineSplit.Length);

        bool conditionPass = false;

        for (int i = 0; i < orIndexes.Count - 1; i++)
        {
            int startIndex = orIndexes[i] + 1;
            int endIndex = orIndexes[i + 1] - 1;

            int comparatorIndex = -1;
            for (int c = startIndex; c <= endIndex; c++)
            {
                if (lineSplit[c] == "rovno" || lineSplit[c] == "aspon" || lineSplit[c] == "nejvic")
                {
                    comparatorIndex = c;
                    break;
                }
            }

            if (comparatorIndex == -1)
            {
                return (false, false);
            }

            string comparator = lineSplit[comparatorIndex];
            (bool, double) expression1Result = ExpressionValue(lineSplit
                    .Skip(startIndex)
                    .Take(comparatorIndex - startIndex)
                    .ToArray(),
                variables);
            (bool, double) expression2Result = ExpressionValue(lineSplit
                .Skip(comparatorIndex + 1)
                .Take(endIndex - comparatorIndex)
                .ToArray(), variables);

            if (!expression1Result.Item1 || !expression2Result.Item1)
            {
                return (false, false);
            }

            if (!conditionPass)
            {
                double expression1 = expression1Result.Item2;
                double expression2 = expression2Result.Item2;

                switch (comparator)
                {
                    case "rovno":
                        conditionPass = expression1 == expression2;
                        break;

                    case "aspon":
                        conditionPass = expression1 >= expression2;
                        break;

                    case "nejvic":
                        conditionPass = expression1 <= expression2;
                        break;
                }
            }
        }

        return (true, conditionPass);
    }
}
