using System;
using System.IO;

class Program
{
    static void Main(string[] args)
    {
        string folderPath = Console.ReadLine();

        if (!Directory.Exists(folderPath))
        {
            Console.WriteLine("not found");
            return;
        }

        PrintDirectoryContents(folderPath);
    }

    static void PrintDirectoryContents(string folderPath, int nestLevel = 0)
    {
        string[] files = Directory.GetFiles(folderPath);
        string[] directories = Directory.GetDirectories(folderPath);
        Array.Sort(files);
        Array.Sort(directories);

        Console.Write(new string(' ', Math.Max(nestLevel - 1, 0) * 2));
        if (nestLevel > 0)
        {
            Console.Write("- ");
        }

        Console.WriteLine(Path.GetFileName(folderPath));

        foreach (string file in files)
        {
            Console.Write(new string(' ', nestLevel * 2));
            Console.WriteLine($"- {Path.GetFileName(file)}");
        }

        foreach (string directory in directories)
        {
            PrintDirectoryContents(directory, nestLevel + 1);
        }
    }
}
