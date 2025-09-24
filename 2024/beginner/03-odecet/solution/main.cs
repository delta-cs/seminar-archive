using System;

internal class Program
{
    static void Main(string[] args)
    {
        int firstNumber = Convert.ToInt32(Console.ReadLine());
        int secondNumber = Convert.ToInt32(Console.ReadLine());
        int result = firstNumber - secondNumber;
        Console.WriteLine(result);
    }
}
