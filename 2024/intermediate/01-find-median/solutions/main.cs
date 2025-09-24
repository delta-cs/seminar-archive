using System;

internal class Program
{
    static void Main(string[] args)
    {
        int K = int.Parse(Console.ReadLine());
        double[] arraynumbers = new double[K];
        for (int i = 0; i < K; i++){
            arraynumbers[i] = int.Parse(Console.ReadLine());
        }
        Array.Sort(arraynumbers);
        if (K % 2 == 0)
        {
            Console.WriteLine((arraynumbers[K / 2] + arraynumbers[(K / 2)-1])/2);
        }
        else
        {
            Console.WriteLine(arraynumbers[K / 2]);
        }
       
    }
}
