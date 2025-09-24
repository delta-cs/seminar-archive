using System;
using System.Collections.Generic;
using System.Linq;

namespace DiceGame {
    internal class Program {
        static void Main(string[] args) {
            // Console.ReadLine();
            string input = Console.ReadLine();

            Dictionary<string, int> dictionary = new Dictionary<string, int>();

            foreach (var VARIABLE in input.Split(' '))
            {
                if (dictionary.ContainsKey(VARIABLE))
                {
                    dictionary[VARIABLE]++;
                }
                else
                {
                    dictionary.Add(VARIABLE, 1);
                }

            }


            Console.WriteLine((dictionary.OrderByDescending(x => x.Value).First()).Key);
        }
    }
}