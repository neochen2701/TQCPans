using System;

class Program
{
    static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int m = int.Parse(input[0]), n = int.Parse(input[1]);

        int[,] adjMatrix = new int[m+1, m+1];
        for (int i = 0; i < n; i++)
        {
            input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]), b = int.Parse(input[1]);
            adjMatrix[a, b] = 1;
            adjMatrix[b, a] = 1;
        }

        int[] degree = new int[m+1];
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                if (adjMatrix[i, j] == 1)
                    degree[i]++;

        int numOfOddDegree = 0;
        for (int i = 1; i <= m; i++)
            if (degree[i] % 2 == 1)
                numOfOddDegree++;

        Console.WriteLine(numOfOddDegree == 0 || numOfOddDegree == 2 ? "YES" : "NO");

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j < m; j++)
                Console.Write(adjMatrix[i, j] + " ");
            Console.WriteLine(adjMatrix[i, m]);
        }
    }
}
