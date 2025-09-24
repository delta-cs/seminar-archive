namespace DiceGame {
    internal class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());

            var allowedWords = Console.ReadLine().Split(' ').ToHashSet();

            int M = int.Parse(Console.ReadLine());

            var sentence = Console.ReadLine().Split(' ');

            foreach (var word in sentence)
            {
                if (!allowedWords.Contains(word))
                {
                    Console.WriteLine(word);
                    return;
                }
            }
        }
}