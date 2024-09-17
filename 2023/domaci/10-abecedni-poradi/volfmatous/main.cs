using System;

internal class Program
{
    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());

        bool descending = false;
        bool descendingDecided = false;
        string previousWord = string.Empty;
        for (int i = 0; i < n; i++)
        {
            string currentWord = Console.ReadLine();

            bool inOrderAscending = AreWordsInOrder(previousWord, currentWord, false);
            bool inOrderDescending = AreWordsInOrder(previousWord, currentWord, true);

            previousWord = currentWord;

            if (descendingDecided)
            {
                if (descending ? !inOrderDescending : !inOrderAscending)
                {
                    Console.WriteLine("unordered");
                    return;
                }
            }
            else
            {
                if (inOrderAscending && inOrderDescending)
                {
                    continue;
                }

                descendingDecided = true;

                if (inOrderAscending)
                {
                    descending = false;
                    continue;
                }

                if (inOrderDescending)
                {
                    descending = true;
                    continue;
                }

                Console.WriteLine("unordered");
                return;
            }
        }

        Console.WriteLine("ordered");
    }

    static bool AreWordsInOrder(string word1, string word2, bool descending)
    {
        bool letterCaseInOrder = true;
        bool letterCaseInOrderDecided = false;

        int shorterLength = Math.Min(word1.Length, word2.Length);
        for (int i = 0; i < shorterLength; i++)
        {
            char char1 = word1[i];
            char char2 = word2[i];

            if (char.ToLower(char1) != char.ToLower(char2))
            {
                bool alphabetAscendingOrder = char.ToLower(char1) < char.ToLower(char2);
                return descending ? !alphabetAscendingOrder : alphabetAscendingOrder;
            }

            if (letterCaseInOrderDecided)
            {
                continue;
            }

            if (char.IsLower(char1) && char.IsUpper(char2))
            {
                letterCaseInOrder = true;
                letterCaseInOrderDecided = true;
                continue;
            }

            if (char.IsUpper(char1) && char.IsLower(char2))
            {
                letterCaseInOrder = false;
                letterCaseInOrderDecided = true;
                continue;
            }
        }

        if (word1.Length != word2.Length)
        {
            return word1.Length < word2.Length;
        }

        return letterCaseInOrder;
    }
}
