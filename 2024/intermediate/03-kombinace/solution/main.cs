using System;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int forbidden = int.Parse(Console.ReadLine());
        int count = 0;

        for (int i = 0; i < Math.Pow(10, n); i++)
        {
            string number = i.ToString();
            
            if (number.Length == n && !number.Contains(forbidden.ToString()) && number[0] != '0')
            {
                count++;
            }

            if (n == 1 && i == 0) // Special case for single digit 0
            {
                count++;
            }
        }
        Console.WriteLine(count);
    }
}
