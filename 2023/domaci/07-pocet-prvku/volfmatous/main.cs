using System;

internal class Program
{
    static void Main(string[] args)
    {
        int inputCount = 0;

        while (Console.ReadLine() != null)
        {
            inputCount++;
        }

        Console.WriteLine(inputCount);
    }
}
