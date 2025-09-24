using System;

class Program
{
    static void Main()
    {
        double maxHeight=0; // nejvyssi bod
        double distance=0; // celkova delka
        double currentHeight=0; // aktualni vyska
        
        int n = int.Parse(Console.ReadLine());
        
        for (int i=0; i<n; i++)
        {
            string[] input = Console.ReadLine().Split(' ');
            double angle = int.Parse(input[0])*(Math.PI/180);
            double lenght = int.Parse(input[1]);
            
            distance += lenght*Math.Cos(angle);
            
            currentHeight += lenght*Math.Sin(angle);
            if (currentHeight>maxHeight)
            {
                maxHeight = currentHeight;
            }
        }
        
        Console.Write($"{Math.Round(maxHeight,2)}\n{Math.Round(distance,2)}");
        
    }
}