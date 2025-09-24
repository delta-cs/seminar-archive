namespace Program;


class Program
{
    static void Main()
    {
        string a = Console.ReadLine();

        int sloupec = a[0] - 'a';
        int radek = a[1] - '1';

        List<string> pozice = new List<string>();

        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                if ((y == radek || x == sloupec || Math.Abs(y - radek) == Math.Abs(x - sloupec))
                    && !(x == sloupec && y == radek))
                {
                    pozice.Add($"{(char)(x + 'a')}{(char)(y + '1')}");
                }
            }
        }

        pozice.Sort();

        Console.WriteLine(string.Join(" ", pozice));
    }
}

