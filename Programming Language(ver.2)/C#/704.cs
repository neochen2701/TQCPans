using System;
using System.Collections.Generic;

public class TQC704
{
    public static void Main(string[] args)
    {
        Dictionary<int, int> counter = new Dictionary<int, int>();
        int n;
        n = int.Parse(Console.ReadLine());
        string[] numberArray = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++) {
            int num = Convert.ToInt32(numberArray[i]);
            if (counter.ContainsKey(num)) {
                counter[num]++;
            }
            else {
                counter[num] = 1;
            }
        }

        int overHalfNum = -1;
        foreach (KeyValuePair<int, int> numCountPair in counter) {
            if (numCountPair.Value > n / 2) {
                overHalfNum = numCountPair.Key;
            }
        }

        if (overHalfNum != -1)
            Console.WriteLine(overHalfNum);
        else
            Console.WriteLine("error");
    }
}