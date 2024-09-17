using System;
using System.Collections.Generic;

internal class Program
{
    const int Left = 0;
    const int Right = 1;
    const int Forward = 2;
    const int Back = 3;

    static void Main(string[] args)
    {
        string[] inputSplit = Console.ReadLine().Split(' ');
        int h = int.Parse(inputSplit[0]);
        int w = int.Parse(inputSplit[1]);

        char[,] floor = new char[h, w];

        List<char> tileColors = new List<char>();
        Dictionary<char, int> program = new Dictionary<char, int>();
        for (int row = 0; row < h; row++)
        {
            string[] rowTiles = Console.ReadLine().Split(' ');

            for (int col = 0; col < w; col++)
            {
                char tile = rowTiles[col][0];
                floor[row, col] = tile;

                if (!program.ContainsKey(tile))
                {
                    program[tile] = Left;
                    tileColors.Add(tile);
                }
            }
        }

        inputSplit = Console.ReadLine().Split(' ');
        int cleanerY = int.Parse(inputSplit[0]) - 1;
        int cleanerX = int.Parse(inputSplit[1]) - 1;

        inputSplit = Console.ReadLine().Split(' ');
        int stationY = int.Parse(inputSplit[0]) - 1;
        int stationX = int.Parse(inputSplit[1]) - 1;

        int totalPossiblePrograms = 0;

        while (true)
        {
            if (TryProgram(floor, cleanerY, cleanerX, stationY, stationX, program))
            {
                totalPossiblePrograms++;
            }

            bool end = false;
            for (int i = 0; i < tileColors.Count; i++)
            {
                program[tileColors[i]]++;
                if (program[tileColors[i]] > 3)
                {
                    if (i >= tileColors.Count - 1)
                    {
                        end = true;
                    }

                    program[tileColors[i]] = 0;
                }
                else
                {
                    break;
                }
            }

            if (end)
            {
                break;
            }
        }

        Console.WriteLine(totalPossiblePrograms);
    }

    static bool TryProgram(char[,] floor, int cleanerY, int cleanerX, int stationY, int stationX,
        Dictionary<char, int> program)
    {
        bool[,] floorVisited = new bool[floor.GetLength(0), floor.GetLength(1)];

        while (true)
        {
            char tile = floor[cleanerY, cleanerX];
            switch (program[tile])
            {
                case Left:
                    cleanerX--;
                    break;
                case Right:
                    cleanerX++;
                    break;
                case Forward:
                    cleanerY--;
                    break;
                case Back:
                    cleanerY++;
                    break;
            }

            if (cleanerY < 0 || cleanerY >= floor.GetLength(0) || cleanerX < 0 || cleanerX >= floor.GetLength(1)
                || floorVisited[cleanerY, cleanerX])
            {
                return false;
            }

            if (cleanerY == stationY && cleanerX == stationX)
            {
                return true;
            }

            floorVisited[cleanerY, cleanerX] = true;
        }
    }
}
