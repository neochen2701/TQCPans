using System;

class Ans
{
    static void Main(string[] args)
    {
        int m = int.Parse(Console.ReadLine());
        int n = int.Parse(Console.ReadLine());

        int[,] matrix = new int[m, n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i, j] = int.Parse(Console.ReadLine());
            }
        }

        Console.WriteLine("Original:");
        for (int i = 0; i < m; i++)
        {
            Console.Write("[");
            for (int j = 0; j < n; j++)
            {
                Console.Write(matrix[i, j]);
                if (j < n - 1)
                {
                    Console.Write(" ");
                }
            }
            Console.WriteLine("]");
        }

        Console.WriteLine("Transpose:");
        for (int i = 0; i < n; i++)
        {
            Console.Write("[");
            for (int j = 0; j < m; j++)
            {
                Console.Write(matrix[j, i]);
                if (j < m - 1)
                {
                    Console.Write(" ");
                }
            }
            Console.WriteLine("]");
        }
    }
}
