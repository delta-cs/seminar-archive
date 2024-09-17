using System;
using System.Collections.Generic;

internal class Program
{
    static void Main(string[] args)
    {
        HashSet<string> dictionaryWords = new HashSet<string>();

        int d = int.Parse(Console.ReadLine());
        for (int i = 0; i < d; i++)
        {
            dictionaryWords.Add(Console.ReadLine());
        }

        Console.ReadLine();

        bool sentenceStarts = true;
        bool previousWordWasNumber = false;

        int l = int.Parse(Console.ReadLine());
        for (int i = 0; i < l; i++)
        {
            string line = Console.ReadLine();

            Console.WriteLine(line);

            if (line.Length < 1)
            {
                continue;
            }

            List<int> errorIndexes = new List<int>();
            List<int> errorLengths = new List<int>();
            List<string> errorMessages = new List<string>();

            int currentIndex = 0;
            bool duplicateSpaceFlag = false;

            string[] words = line.Split(' ');

            foreach (string w in words)
            {
                string word = w;

                if (word.Length < 1)
                {
                    if (duplicateSpaceFlag)
                    {
                        errorLengths[errorLengths.Count - 1]++;
                    }
                    else
                    {
                        errorIndexes.Add(Math.Max(0, currentIndex - 1));
                        errorLengths.Add(2);
                        errorMessages.Add("duplicate space");
                        duplicateSpaceFlag = true;
                    }

                    currentIndex++;
                    continue;
                }

                duplicateSpaceFlag = false;

                bool endsWithDot = false;
                if (word.EndsWith('.'))
                {
                    word = word.Substring(0, word.Length - 1);
                    endsWithDot = true;
                }

                bool isNumber = true;
                foreach (char c in word)
                {
                    if (!char.IsDigit(c))
                    {
                        isNumber = false;
                        break;
                    }
                }

                string wordCapitalized = char.ToUpper(word[0]) + word.Substring(1);
                string wordLowercase = word.ToLower();

                if (isNumber)
                {
                    if (word.Length > 3)
                    {
                        errorIndexes.Add(currentIndex);
                        errorLengths.Add(word.Length);
                        errorMessages.Add("incorrect number formatting");
                    }
                }
                else if (!dictionaryWords.Contains(wordCapitalized) && !dictionaryWords.Contains(wordLowercase))
                {
                    errorIndexes.Add(currentIndex);
                    errorLengths.Add(word.Length);
                    errorMessages.Add("unknown word");
                }
                else if (char.IsUpper(word[0]) && !sentenceStarts && !previousWordWasNumber && !dictionaryWords.Contains(word))
                {
                    errorIndexes.Add(currentIndex);
                    errorLengths.Add(word.Length);
                    errorMessages.Add("incorrect leading uppercase");
                }
                else if (char.IsLower(word[0]) && (sentenceStarts || !dictionaryWords.Contains(wordLowercase)))
                {
                    errorIndexes.Add(currentIndex);
                    errorLengths.Add(word.Length);
                    errorMessages.Add("incorrect leading lowercase");
                }

                currentIndex += w.Length + 1;
                sentenceStarts = endsWithDot && !isNumber;
                previousWordWasNumber = isNumber;
            }

            if (errorIndexes.Count < 1)
            {
                continue;
            }

            currentIndex = 0;
            for (int j = 0; j < errorIndexes.Count; j++)
            {
                for (int k = 0; k < errorIndexes[j] - currentIndex; k++)
                {
                    Console.Write(' ');
                }

                for (int k = 0; k < errorLengths[j]; k++)
                {
                    Console.Write('~');
                }

                currentIndex = errorIndexes[j] + errorLengths[j];
            }

            Console.WriteLine();

            currentIndex = 0;
            for (int j = 0; j < errorIndexes.Count; j++)
            {
                for (int k = 0; k < errorIndexes[j] - currentIndex; k++)
                {
                    Console.Write(' ');
                }

                Console.Write('^');

                currentIndex = errorIndexes[j] + 1;
            }

            Console.WriteLine();

            for (int lineIndex = 0; lineIndex < errorIndexes.Count * 2; lineIndex++)
            {
                currentIndex = 0;

                for (int j = 0; j < errorIndexes.Count - lineIndex / 2; j++)
                {
                    for (int k = 0; k < errorIndexes[j] - currentIndex; k++)
                    {
                        Console.Write(' ');
                    }

                    if (j == errorIndexes.Count - (lineIndex + 1) / 2)
                    {
                        Console.Write("----- " + errorMessages[j]);
                    }
                    else
                    {
                        Console.Write('|');
                    }

                    currentIndex = errorIndexes[j] + 1;
                }

                Console.WriteLine();
            }

            Console.WriteLine();
        }
    }
}
