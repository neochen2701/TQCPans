using System;
using System.Collections.Generic;

public class Ans
{
    public static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        int x = int.Parse(Console.ReadLine());

        Queue<int> allIds = new Queue<int>();
        for (int i = 1; i <= n; i++)
            allIds.Enqueue(i);

        while (allIds.Count > 1)
        {
            for (int i = 1; i < x; i++)
            {
                int t = allIds.Dequeue();
                allIds.Enqueue(t);
            }
            allIds.Dequeue();
        }
        Console.WriteLine(allIds.Dequeue());
    }
}
