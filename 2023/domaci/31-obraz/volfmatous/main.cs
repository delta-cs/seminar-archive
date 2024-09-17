using System;

internal class Program
{
    const int Left = 0;
    const int Right = 1;
    const int Top = 2;
    const int Bottom = 3;
    const char NailChar = 'o';
    const int TopEdgeNailCount = 2;

    static void Main(string[] args)
    {
        int w = int.Parse(Console.ReadLine());
        int h = int.Parse(Console.ReadLine());
        Console.ReadLine();

        if (w < 1 || h < 1)
        {
            return;
        }

        char[,] picture = new char[h, w];

        for (int row = 0; row < h; row++)
        {
            for (int col = 0; col < w; col++)
            {
                picture[row, col] = char.Parse(Console.ReadLine());
            }
        }

        int topEdgeSide = GetTopEdgeSide(picture);
        PrintPictureFromSide(picture, topEdgeSide);
    }

    static int GetTopEdgeSide(char[,] picture)
    {
        int nailsCount = 0;

        for (int row = 0; row < picture.GetLength(0); row++)
        {
            if (picture[row, 0] == NailChar)
            {
                nailsCount++;

                if (nailsCount >= TopEdgeNailCount)
                {
                    return Left;
                }
            }
        }

        nailsCount = 0;

        for (int row = 0; row < picture.GetLength(0); row++)
        {
            if (picture[row, picture.GetLength(1) - 1] == NailChar)
            {
                nailsCount++;

                if (nailsCount >= TopEdgeNailCount)
                {
                    return Right;
                }
            }
        }

        nailsCount = 0;

        for (int col = 0; col < picture.GetLength(1); col++)
        {
            if (picture[0, col] == NailChar)
            {
                nailsCount++;

                if (nailsCount >= TopEdgeNailCount)
                {
                    return Top;
                }
            }
        }

        return Bottom;
    }

    static void PrintPictureFromSide(char[,] picture, int side)
    {
        switch (side)
        {
            case Left:
                for (int col = 0; col < picture.GetLength(1); col++)
                {
                    for (int row = picture.GetLength(0) - 1; row >= 0; row--)
                    {
                        char output = picture[row, col];

                        if (col == 0 || col == picture.GetLength(1) - 1
                                     || row == 0 || row == picture.GetLength(0) - 1)
                        {
                            switch (output)
                            {
                                case '|':
                                    output = '-';
                                    break;

                                case '-':
                                    output = '|';
                                    break;
                            }
                        }

                        Console.Write(output);
                    }

                    Console.WriteLine();
                }

                break;

            case Right:
                for (int col = picture.GetLength(1) - 1; col >= 0; col--)
                {
                    for (int row = 0; row < picture.GetLength(0); row++)
                    {
                        char output = picture[row, col];

                        if (col == 0 || col == picture.GetLength(1) - 1
                                     || row == 0 || row == picture.GetLength(0) - 1)
                        {
                            switch (output)
                            {
                                case '|':
                                    output = '-';
                                    break;

                                case '-':
                                    output = '|';
                                    break;
                            }
                        }

                        Console.Write(output);
                    }

                    Console.WriteLine();
                }

                break;

            case Top:
                for (int row = 0; row < picture.GetLength(0); row++)
                {
                    for (int col = 0; col < picture.GetLength(1); col++)
                    {
                        Console.Write(picture[row, col]);
                    }

                    Console.WriteLine();
                }

                break;

            case Bottom:
                for (int row = picture.GetLength(0) - 1; row >= 0; row--)
                {
                    for (int col = picture.GetLength(1) - 1; col >= 0; col--)
                    {
                        Console.Write(picture[row, col]);
                    }

                    Console.WriteLine();
                }

                break;
        }
    }
}
