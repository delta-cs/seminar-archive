using System.Diagnostics.Metrics;
using System;

internal class Program
{
    static void Main(string[] args)
    {

        string text = Console.ReadLine();
        string newtext = "";
        for (int i = 0; i < text.Length; i++) {
            newtext += decipherOneChar(text[i]);
        }
        Console.WriteLine(newtext);
        
    }

    static char decipherOneChar(char input) { 
        if(input >= 'a' && input <= 'z')
        {
            int halfAlphabet = ('z' - 'a') / 2 + 1;
            if (input < 'a' + halfAlphabet)
            {
                return (char)(input + halfAlphabet);
            }
            else if (input >= 'a' + halfAlphabet)
            {
                return (char)(input - halfAlphabet);
            }
        }
        if (input >= 'A' && input <= 'Z')
        {
            int halfAlphabet = ('Z' - 'A') / 2 + 1;
            if (input < 'A' + halfAlphabet)
            {
                return (char)(input + halfAlphabet);
            }
            else if (input >= 'A' + halfAlphabet)
            {
                return (char)(input - halfAlphabet);
            }
        }
        return input;



    }
}
