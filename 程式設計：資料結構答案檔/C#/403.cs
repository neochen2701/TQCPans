using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] firstLine = Console.ReadLine().Split(' ');
        int n = int.Parse(firstLine[0]);
        int v = int.Parse(firstLine[1]);
        int threshold = int.Parse(firstLine[2]);

        bool[] visited = new bool[n + 1];
        List<KeyValuePair<int, int>>[] node = new List<KeyValuePair<int, int>>[n + 1];
        for (int i = 0; i <= n; i++)
        {
            node[i] = new List<KeyValuePair<int, int>>();
        }

        for (int i = 0; i < n - 1; i++)
        {
            string[] edge = Console.ReadLine().Split(' ');
            int v0 = int.Parse(edge[0]);
            int v1 = int.Parse(edge[1]);
            int w = int.Parse(edge[2]);

            node[v0].Add(new KeyValuePair<int, int>(v1, w));
            node[v1].Add(new KeyValuePair<int, int>(v0, w));
        }

        visited[v] = true;
        Queue<KeyValuePair<int, int>> q = new Queue<KeyValuePair<int, int>>();
        q.Enqueue(new KeyValuePair<int, int>(v, int.MaxValue));

        int ans = 0;
        while (q.Count > 0)
        {
            KeyValuePair<int, int> t = q.Dequeue();
            foreach (var p in node[t.Key])
            {
                if (!visited[p.Key])
                {
                    visited[p.Key] = true;
                    int minWeight = Math.Min(t.Value, p.Value);
                    if (minWeight >= threshold)
                    {
                        ans++;
                        q.Enqueue(new KeyValuePair<int, int>(p.Key, minWeight));
                    }
                }
            }
        }

        Console.WriteLine(ans);
    }
}
