using System;
using System.Collections.Generic;

internal class Program
{
    static void Main(string[] args)
    {
        string path1 = Console.ReadLine();
        string path2 = Console.ReadLine();

        bool path2IsAbsolute = path2.StartsWith('/');

        List<string> path1Segments = DividePath(path1);
        List<string> path2Segments = DividePath(path2);

        string result = string.Empty;

        if (path2IsAbsolute)
        {
            int longerPathLength = Math.Max(path1Segments.Count, path2Segments.Count);
            for (int i = 0; i < longerPathLength; i++)
            {
                if (i < path1Segments.Count && i < path2Segments.Count && path1Segments[i] == path2Segments[i])
                {
                    continue;
                }

                for (int j = i; j < path1Segments.Count; j++)
                {
                    result += "../";
                }

                for (int j = i; j < path2Segments.Count; j++)
                {
                    result += path2Segments[j] + "/";
                }

                break;
            }
        }
        else
        {
            foreach (string segment in path2Segments)
            {
                if (segment == "..")
                {
                    if (path1Segments.Count < 1)
                    {
                        continue;
                    }

                    path1Segments.RemoveAt(path1Segments.Count - 1);
                }
                else
                {
                    path1Segments.Add(segment);
                }
            }

            result = "/";
            foreach (string segment in path1Segments)
            {
                result += segment + "/";
            }
        }

        Console.WriteLine(result);
    }

    static List<string> DividePath(string path)
    {
        string[] pathSplit = path.Split('/');
        bool pathIsAbsolute = path.StartsWith('/');

        List<string> pathSimplified = new List<string>();
        for (int i = pathIsAbsolute ? 1 : 0; i < pathSplit.Length - 1; i++)
        {
            string segment = pathSplit[i];

            if (pathIsAbsolute && segment == "..")
            {
                if (pathSimplified.Count < 1)
                {
                    continue;
                }

                pathSimplified.RemoveAt(pathSimplified.Count - 1);
            }
            else
            {
                pathSimplified.Add(segment);
            }
        }

        return pathSimplified;
    }
}
