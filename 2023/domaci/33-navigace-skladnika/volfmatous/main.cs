using System;

internal class Program
{
    const int Left = 0;
    const int Up = 1;
    const int Right = 2;
    const int Down = 3;

    const int None = 0;
    const int Robot = 1;
    const int Pillar = 2;
    const int Box = 3;

    static void Main(string[] args)
    {
        int w = ReadInt();
        int h = ReadInt();
        Console.ReadLine();

        int robotX = ReadInt() - 1;
        int robotY = ReadInt() - 1;
        Console.ReadLine();
        int robotOrientation = Left;

        int[,] warehouse = new int[w, h];
        warehouse[robotX, robotY] = Robot;

        int p = ReadInt();
        Console.ReadLine();
        for (int i = 0; i < p; i++)
        {
            warehouse[ReadInt() - 1, ReadInt() - 1] = Pillar;
            Console.ReadLine();
        }

        int b = ReadInt();
        Console.ReadLine();
        for (int i = 0; i < b; i++)
        {
            warehouse[ReadInt() - 1, ReadInt() - 1] = Box;
            Console.ReadLine();
        }

        int c = ReadInt();
        Console.ReadLine();
        for (int i = 0; i < c; i++)
        {
            char command = char.Parse(Console.ReadLine());

            switch (command)
            {
                case 'L':
                case 'R':
                    robotOrientation = Rotate(robotOrientation, command == 'R');
                    break;

                case 'F':
                    int[] newPosition = MoveForward(warehouse, robotX, robotY, robotOrientation);
                    robotX = newPosition[0];
                    robotY = newPosition[1];
                    break;
            }
        }

        PrintWarehouse(warehouse);
    }

    static int Rotate(int currentOrientation, bool clockwise)
    {
        if (clockwise)
        {
            return (currentOrientation + 1) % 4;
        }
        else
        {
            return (currentOrientation - 1 + 4) % 4;
        }
    }

    static int[] MoveForward(int[,] warehouse, int robotX, int robotY, int orientation)
    {
        switch (orientation)
        {
            case Left:
                for (int col = robotX - 1; col >= 0; col--)
                {
                    if (warehouse[col, robotY] == Pillar)
                    {
                        break;
                    }

                    if (warehouse[col, robotY] == Box)
                    {
                        continue;
                    }

                    for (int col2 = col + 1; col2 <= robotX; col2++)
                    {
                        warehouse[col2 - 1, robotY] = warehouse[col2, robotY];
                    }

                    warehouse[robotX, robotY] = None;
                    return new int[] { robotX - 1, robotY };
                }

                break;

            case Right:
                for (int col = robotX + 1; col < warehouse.GetLength(0); col++)
                {
                    if (warehouse[col, robotY] == Pillar)
                    {
                        break;
                    }

                    if (warehouse[col, robotY] == Box)
                    {
                        continue;
                    }

                    for (int col2 = col - 1; col2 >= robotX; col2--)
                    {
                        warehouse[col2 + 1, robotY] = warehouse[col2, robotY];
                    }

                    warehouse[robotX, robotY] = None;
                    return new int[] { robotX + 1, robotY };
                }

                break;

            case Up:
                for (int row = robotY - 1; row >= 0; row--)
                {
                    if (warehouse[robotX, row] == Pillar)
                    {
                        break;
                    }

                    if (warehouse[robotX, row] == Box)
                    {
                        continue;
                    }

                    for (int row2 = row + 1; row2 <= robotY; row2++)
                    {
                        warehouse[robotX, row2 - 1] = warehouse[robotX, row2];
                    }

                    warehouse[robotX, robotY] = None;
                    return new int[] { robotX, robotY - 1 };
                }

                break;

            case Down:
                for (int row = robotY + 1; row < warehouse.GetLength(1); row++)
                {
                    if (warehouse[robotX, row] == Pillar)
                    {
                        break;
                    }

                    if (warehouse[robotX, row] == Box)
                    {
                        continue;
                    }

                    for (int row2 = row - 1; row2 >= robotY; row2--)
                    {
                        warehouse[robotX, row2 + 1] = warehouse[robotX, row2];
                    }

                    warehouse[robotX, robotY] = None;
                    return new int[] { robotX, robotY + 1 };
                }

                break;
        }

        return new int[] { robotX, robotY };
    }

    static void PrintWarehouse(int[,] warehouse)
    {
        for (int i = 0; i < warehouse.GetLength(0) + 2; i++)
        {
            Console.Write('.');
        }

        Console.WriteLine();

        for (int row = 0; row < warehouse.GetLength(1); row++)
        {
            Console.Write('.');

            for (int col = 0; col < warehouse.GetLength(0); col++)
            {
                char output = ' ';

                switch (warehouse[col, row])
                {
                    case Robot:
                        output = 'r';
                        break;

                    case Pillar:
                        output = 'o';
                        break;

                    case Box:
                        output = '#';
                        break;
                }

                Console.Write(output);
            }

            Console.WriteLine('.');
        }

        for (int i = 0; i < warehouse.GetLength(0) + 2; i++)
        {
            Console.Write('.');
        }

        Console.WriteLine();
    }

    static int ReadInt()
    {
        return int.Parse(Console.ReadLine());
    }
}
