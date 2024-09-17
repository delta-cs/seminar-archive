using System;

internal class Program
{
    const int SymbolWinCount = 5;

    static void Main(string[] args)
    {
        int w = ReadInt();
        int h = ReadInt();
        int t = ReadInt();
        bool currentPlayerIsA = Console.ReadLine() == "A";
        Console.ReadLine();

        int[,] board = new int[w, h];

        for (int i = 0; i < t; i++)
        {
            int turnX = ReadInt() - 1;
            int turnY = ReadInt() - 1;
            Console.ReadLine();

            if (board[turnX, turnY] != 0)
            {
                Console.WriteLine("invalid");
                Console.WriteLine(i + 1);
                return;
            }

            board[turnX, turnY] = currentPlayerIsA ? 1 : 2;

            if (IsWin(board, turnX, turnY))
            {
                Console.WriteLine(currentPlayerIsA ? 'A' : 'B');
                Console.WriteLine(i + 1);
                return;
            }

            currentPlayerIsA = !currentPlayerIsA;
        }

        Console.WriteLine('?');
    }

    static bool IsWin(int[,] board, int turnX, int turnY)
    {
        int symbolCountHorizontal = 0;
        int symbolCountVertical = 0;
        int symbolCountDiagonal1 = 0;
        int symbolCountDiagonal2 = 0;

        for (int i = -SymbolWinCount + 1; i <= SymbolWinCount - 1; i++)
        {
            int x = turnX + i;
            int y = turnY;

            if (HasCoordinates(board, x, y) && board[x, y] == board[turnX, turnY])
            {
                symbolCountHorizontal++;
            }
            else
            {
                symbolCountHorizontal = 0;
            }

            x = turnX;
            y = turnY + i;

            if (HasCoordinates(board, x, y) && board[x, y] == board[turnX, turnY])
            {
                symbolCountVertical++;
            }
            else
            {
                symbolCountVertical = 0;
            }

            x = turnX + i;
            y = turnY + i;

            if (HasCoordinates(board, x, y) && board[x, y] == board[turnX, turnY])
            {
                symbolCountDiagonal1++;
            }
            else
            {
                symbolCountDiagonal1 = 0;
            }

            x = turnX + i;
            y = turnY - i;

            if (HasCoordinates(board, x, y) && board[x, y] == board[turnX, turnY])
            {
                symbolCountDiagonal2++;
            }
            else
            {
                symbolCountDiagonal2 = 0;
            }

            if (symbolCountHorizontal >= SymbolWinCount ||
                symbolCountVertical >= SymbolWinCount ||
                symbolCountDiagonal1 >= SymbolWinCount ||
                symbolCountDiagonal2 >= SymbolWinCount)
            {
                return true;
            }
        }

        return false;
    }

    static bool HasCoordinates(int[,] board, int x, int y)
    {
        return x >= 0 && x < board.GetLength(0) && y >= 0 && y < board.GetLength(1);
    }

    static int ReadInt()
    {
        return int.Parse(Console.ReadLine());
    }
}
