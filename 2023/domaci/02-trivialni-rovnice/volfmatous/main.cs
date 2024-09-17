using System;

internal class Program
{
    static void Main(string[] args)
    {
        double a = double.Parse(Console.ReadLine());
        double b = double.Parse(Console.ReadLine());
        double c = double.Parse(Console.ReadLine());

        string output;
        if (b == 1)
        {
            output = "undefined";
        }
        else
        {
            double x = (c - a) / (b + 1);
            output = x.ToString();
        }

        Console.WriteLine(output);
    }
}
