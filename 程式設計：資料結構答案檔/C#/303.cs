using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Dictionary<string, int> combinationsCount = new Dictionary<string, int>();

        for (int i = 0; i < n; i++)
        {
            var fruits = Console.ReadLine().Split(' ').ToList();
            fruits.Sort();

            for (int j = 0; j < fruits.Count; j++)
            {
                for (int k = j + 1; k < fruits.Count; k++)
                {
                    string combination = fruits[j] + " " + fruits[k];
                    if (combinationsCount.ContainsKey(combination))
                    {
                        combinationsCount[combination]++;
                    }
                    else
                    {
                        combinationsCount.Add(combination, 1);
                    }
                }
            }
        }

        var sortedCombinations = combinationsCount.ToList();
        sortedCombinations.Sort((pair1, pair2) =>
        {
            int countCompare = pair2.Value.CompareTo(pair1.Value);
            if (countCompare == 0)
            {
                return pair2.Key.CompareTo(pair1.Key);
            }
            return countCompare;
        });

        for (int i = 0; i < Math.Min(3, sortedCombinations.Count); i++)
        {
            Console.WriteLine($"{sortedCombinations[i].Key} {sortedCombinations[i].Value}");
        }
    }
}
