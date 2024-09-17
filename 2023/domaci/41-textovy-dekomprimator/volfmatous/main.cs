using System;

internal class Program
{
    static void Main(string[] args)
    {
        string text = Console.ReadLine();
        bool compressing = Console.ReadLine() == "compress";

        if (compressing)
        {
            int currentLetterCount = 1;

            for (int i = 0; i < text.Length; i++)
            {
                if (i < text.Length - 1 && text[i] == text[i + 1])
                {
                    currentLetterCount++;
                }
                else
                {
                    Console.Write(text[i]);
                    if (currentLetterCount > 1)
                    {
                        Console.Write(currentLetterCount);
                    }

                    currentLetterCount = 1;
                }
            }
        }
        else
        {
            for (int i = 0; i < text.Length; i++)
            {
                Console.Write(text[i]);

                string countBuffer = string.Empty;
                for (int j = i; j < text.Length; j++)
                {
                    if (j < text.Length - 1 && char.IsDigit(text[j + 1]))
                    {
                        countBuffer += text[j + 1];
                    }
                    else
                    {
                        if (countBuffer.Length > 0)
                        {
                            for (int k = 0; k < int.Parse(countBuffer) - 1; k++)
                            {
                                Console.Write(text[i]);
                            }
                        }

                        i = j;
                        break;
                    }
                }
            }
        }

        Console.WriteLine();
    }
}
