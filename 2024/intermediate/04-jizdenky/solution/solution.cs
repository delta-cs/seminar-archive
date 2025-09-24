using System;

class Program
{
    static void Main()
    {
        int number_of_days = int.Parse(Console.ReadLine());
        int daily_ticket_price = int.Parse(Console.ReadLine());
        int weekly_ticket_price = int.Parse(Console.ReadLine());

        if (number_of_days * daily_ticket_price < number_of_days * weekly_ticket_price / 7){
            Console.WriteLine("denni");
        }
        else{
            Console.WriteLine("tydenni");
        }
        
    }
}
