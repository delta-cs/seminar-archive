using System;

internal class Program
{
    static void Main(string[] args)
    {
        int n = ReadInt();
        int p = ReadInt();

        PrintMultiplicationTable(n, p);
    }

    static void PrintMultiplicationTable(int n, int count)
    {
        for (int multiplier = 1; multiplier <= count; multiplier++)
        {
            Console.WriteLine(n * multiplier);
        }
    }

    static int ReadInt()
    {
        return int.Parse(Console.ReadLine());
    }
}
