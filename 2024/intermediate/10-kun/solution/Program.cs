namespace Program;


class Program
{
    static void Main()
    {
        string a = Console.ReadLine();

        int sloupec = a[0] - 'a';
        int radek = a[1] - '1';

        List<string> pozice = new List<string>();

        int[,] pohyby = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
            };

        for (int i = 0; i < pohyby.GetLength(0); i++)
        {
            int novaRadek = radek + pohyby[i, 0];
            int novaSloupec = sloupec + pohyby[i, 1];

            if (novaRadek >= 0 && novaRadek < 8 && novaSloupec >= 0 && novaSloupec < 8)
            {
                pozice.Add($"{(char)(novaSloupec + 'a')}{(char)(novaRadek + '1')}");
            }
        }

        pozice.Sort();

        Console.WriteLine(string.Join(" ", pozice));
    }
}

