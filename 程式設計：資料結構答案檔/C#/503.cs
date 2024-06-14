using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        string[] firstLine = Console.ReadLine().Split(' ');
        int n1 = int.Parse(firstLine[0]);
        int n2 = int.Parse(firstLine[1]);

        List<int> A = new List<int>(new int[n1 + 1]);
        List<int> B = new List<int>(new int[n2 + 1]);

        string[] AInputs = Console.ReadLine().Split(' ');
        for (int i = 1; i <= n1; i++)
        {
            A[i] = int.Parse(AInputs[i - 1]);
        }

        string[] BInputs = Console.ReadLine().Split(' ');
        for (int j = 1; j <= n2; j++)
        {
            B[j] = int.Parse(BInputs[j - 1]);
        }

        List<int> DP = new List<int>(new int[n2 + 1]);

        for (int i = 1; i <= n1; i++)
        {
            List<int> temp = new List<int>(new int[n2 + 1]);
            for (int j = 1; j <= n2; j++)
            {
                if (A[i] != B[j])
                {
                    temp[j] = Math.Max(temp[j - 1], DP[j]);
                }
                else
                {
                    temp[j] = DP[j - 1] + 1;
                }
            }
            DP = temp;
        }

        Console.WriteLine(DP[n2]);
    }
}
