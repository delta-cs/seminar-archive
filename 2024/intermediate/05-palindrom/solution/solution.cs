using System;

class Program
{
    static bool JePalindrom(string s)
    {
        int length = s.Length;
        for (int i = 0; i < length / 2; i++)
        {
            if (s[i] != s[length - i - 1])
                return false;
        }
        return true;
    }

    static string NajdiPalindrom(string text)
    {
        string nejdelsi = "";
        for (int i = 0; i < text.Length; i++)
        {
            for (int j = i + nejdelsi.Length + 1; j <= text.Length; j++)
            {
                string sub = text.Substring(i, j - i);
                if (JePalindrom(sub) && sub.Length > nejdelsi.Length)
                {
                    nejdelsi = sub;
                }
            }
        }
        return nejdelsi;
    }

    static void Main()
    {
        Console.WriteLine(NajdiPalindrom(Console.ReadLine()));
    }
}