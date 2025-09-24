namespace DiceGame {
    internal class Program {
        static void Main()
        {
            int pocet_pokoju = int.Parse(Console.ReadLine());
            int[] pokoje = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int celkovyZaci = int.Parse(Console.ReadLine());

            int[] array = new int[pokoje.Sum()];
            for (int i = 0; i < pokoje.Sum(); i++)
            {
                if (i >= celkovyZaci)
                {
                    array[i] = 0;
                }
                else
                {
                    array[i] = i + 1;
                }

            }

            List<int[]> permutations = new List<int[]>();
            GeneratePermutations(array, 0, permutations);

            permutations = permutations.Distinct(new IntArrayComparer()).ToList();


            int[,] kamaradi = new int[int.Parse(Console.ReadLine()), 2];

            for (int i = 0; i < kamaradi.GetLength(0); i++)
            {
                int[] fri = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
                kamaradi[i, 0] = fri[0];
                kamaradi[i, 1] = fri[1];
            }

            int[,] nekamaradi = new int[int.Parse(Console.ReadLine()), 2];

            for (int i = 0; i < nekamaradi.GetLength(0); i++)
            {
                int[] nefri = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
                nekamaradi[i, 0] = nefri[0];
                nekamaradi[i, 1] = nefri[1];
            }


            for (int a = 0; a < permutations.Count(); a++)
            {
                bool jemozne = true;
                for (int b = 0; b < pocet_pokoju && jemozne; b++)
                {
                    var _przatim = permutations[a].Skip(pokoje.Skip(0).Take(b + 1).ToArray().Sum()).Take(pokoje[b] + 1).ToArray();

                    for (int c = 0; c < kamaradi.GetLength(0) && jemozne; c++)
                    {

                        if (_przatim.Contains(kamaradi[c, 0]) ^ _przatim.Contains(kamaradi[c, 1]))
                        {
                            jemozne = false;
                        }

                    }

                    for (int c = 0; c < nekamaradi.GetLength(0) && jemozne; c++)
                    {

                        if (_przatim.Contains(nekamaradi[c, 0]) && _przatim.Contains(nekamaradi[c, 1]))
                        {
                            jemozne = false;
                        }

                    }
                }
                if (jemozne) Console.WriteLine(string.Join(", ", permutations[a]) + " - " + jemozne);
            }


        }

        static void GeneratePermutations(int[] array, int start, List<int[]> result)
        {
            if (start == array.Length - 1)
            {
                result.Add((int[])array.Clone());
                return;
            }

            for (int i = start; i < array.Length; i++)
            {
                Swap(array, start, i);
                GeneratePermutations(array, start + 1, result);
                Swap(array, start, i);
            }
        }

        static void Swap(int[] array, int i, int j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }

        class IntArrayComparer : IEqualityComparer<int[]>
        {
            public bool Equals(int[] x, int[] y)
            {
                return x.SequenceEqual(y);
            }

            public int GetHashCode(int[] obj)
            {
                return obj.Aggregate(0, (hash, item) => hash * 31 + item);
            }
        }

    }
}