using System;
using System.IO;

internal class Program
{
    static void Main(string[] args)
    {
        string filePath = Console.ReadLine();

        if (!File.Exists(filePath))
        {
            Console.WriteLine("not found");
            return;
        }

        string content = File.ReadAllText(filePath);
        Console.WriteLine(content);
    }
}
