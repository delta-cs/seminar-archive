using System;
using System.IO;
using System.IO.Compression;

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

        using (ZipArchive zipArchive = ZipFile.OpenRead(filePath))
        {
            foreach (ZipArchiveEntry entry in zipArchive.Entries)
            {
                if (entry.FullName == "input.txt")
                {
                    using (StreamReader reader = new StreamReader(entry.Open()))
                    {
                        string line;
                        while ((line = reader.ReadLine()) != null)
                        {
                            Console.WriteLine(line);
                        }
                    }
                    return;
                }
            }
        }
    }
}
