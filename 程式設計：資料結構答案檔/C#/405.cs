using System;

class Program
{
    static void Main(string[] args)
    {
        string[] firstLine = Console.ReadLine().Split(' ');
        int m = int.Parse(firstLine[0]);
        int n = int.Parse(firstLine[1]);

        string[] secondLine = Console.ReadLine().Split(' ');
        int s = int.Parse(secondLine[0]);
        int t = int.Parse(secondLine[1]);

        double[,] adjArrayOfGraph = new double[m + 1, m + 1];
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                adjArrayOfGraph[i, j] = double.PositiveInfinity;
            }
        }

        for (int i = 0; i < n; i++)
        {
            string[] data = Console.ReadLine().Split(' ');
            int v1 = int.Parse(data[0]);
            int v2 = int.Parse(data[1]);
            double w = double.Parse(data[2]);
            adjArrayOfGraph[v1, v2] = w;
            adjArrayOfGraph[v2, v1] = w;
        }

        double[] distance = new double[m + 1];
        for (int i = 0; i <= m; i++)
        {
            distance[i] = double.PositiveInfinity;
        }
        distance[s] = 0;

        bool[] visited = new bool[m + 1];

        for (int i = 0; i < m; i++)
        {
            double minDistance = double.PositiveInfinity;
            int minIndex = -1;
            for (int j = 1; j <= m; j++)
            {
                if (!visited[j] && distance[j] < minDistance)
                {
                    minDistance = distance[j];
                    minIndex = j;
                }
            }

            if (minIndex == -1)
            {
                break;
            }

            visited[minIndex] = true;

            for (int j = 1; j <= m; j++)
            {
                if (!visited[j] && adjArrayOfGraph[minIndex, j] != double.PositiveInfinity)
                {
                    double newDist = distance[minIndex] + adjArrayOfGraph[minIndex, j];
                    if (newDist < distance[j])
                    {
                        distance[j] = newDist;
                    }
                }
            }
        }

        Console.WriteLine($"{Math.Round(distance[t], 1):0.0}");
    }
}
