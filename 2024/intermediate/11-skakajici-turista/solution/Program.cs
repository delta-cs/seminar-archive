using System;

internal class Program {
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int len = int.Parse(Console.ReadLine());
        int[] jumps = new int[n];
        jumps[0] = 1;
        for (int i = 1; i < n; i++)
        {
            jumps[i] = secti(i-1, len, jumps);
        }

        Console.WriteLine(jumps[jumps.Length-1]);
    }
    public static int secti(int start, int len, int[] jumps)
    {
        int sum = 0;
        for (int i = start; i > start-len; i--)
        {
            if(i < 0)
            {
                return sum;
            }
            sum += jumps[i];
        }
        return sum;
    }
    
    
}