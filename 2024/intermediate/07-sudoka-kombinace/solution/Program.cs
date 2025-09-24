using System;
using System.Diagnostics.CodeAnalysis;
using System.Runtime.InteropServices;


namespace Pocitadlo;

class Program
{
    static void Main(string[] args)
    {
        var sudoka = new char[9, 9];
        for (int i = 0; i < 9;i++)
        {
            string[] item = Console.ReadLine()!.Split(" ");
            for (int j = 0; j < item.Length; j++)
            {
                sudoka[i, j] = item[j][0];
            }
        }
        
        int solutions = 0;
        
        solve(sudoka,ref solutions);

        Console.WriteLine(solutions);
        
    }  
    private static bool solve(char[,] board, ref int solutions)  
    {  
        for (int i = 0; i < board.GetLength(0); i++)  
        {  
            for (int j = 0; j < board.GetLength(1); j++)  
            {  
                if (board[i, j] == '.')  
                {  
                    for (char c = '1'; c <= '9'; c++)  
                    {  
                        if (isValid(board, i, j, c))  
                        {  
                            board[i, j] = c;

                            solve(board, ref solutions); 
                            board[i, j] = '.';
                        }
                    }  
                    return false;  
                }  
            }  
        } 
        solutions++;
        return true;
    }  
    private static bool isValid(char[,] board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)  
        {  
            //check row  
            if (board[i, col] != '.' && board[i, col] == c)  
                return false;  
            //check column  
            if (board[row, i] != '.' && board[row, i] == c)  
                return false;  
            //check 3*3 block  
            if (board[3 * (row / 3) + i / 3, 3 * (col / 3) + i % 3] != '.' && board[3 * (row / 3) + i / 3, 3 * (col / 3) + i % 3] == c)  
                return false;  
        }  
        return true;  
    }

}