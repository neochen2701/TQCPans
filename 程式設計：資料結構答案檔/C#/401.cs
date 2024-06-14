using System;
using System.IO;
using System.Linq;

class GraphReader
{
    static void Main(string[] args)
    {
        string filename = "read.txt";
        int[][] graph;
        int numVertices = 0;
        
        try
        {
            var lines = File.ReadAllLines(filename);
            numVertices = lines[0].Split(',').Length;
            graph = new int[numVertices][];
            
            for (int i = 0; i < lines.Length; i++)
            {
                graph[i] = lines[i].Split(',')
                                   .Select(int.Parse)
                                   .ToArray();
            }

            int[] degrees = new int[numVertices];
            int maxWeight = 0, minWeight = int.MaxValue;

            for (int i = 0; i < numVertices; i++)
            {
                int weightSum = 0;
                for (int j = 0; j < numVertices; j++)
                {
                    if (graph[i][j] > 0)
                    {
                        degrees[i]++;
                        weightSum += graph[i][j];
                    }
                }
                maxWeight = Math.Max(maxWeight, weightSum);
                minWeight = Math.Min(minWeight, weightSum);
            }

            Console.Write("Degree:");
            for (int i = 0; i < numVertices - 1; i++)
            {
                Console.Write($"{degrees[i]},");
            }
            Console.WriteLine(degrees[numVertices - 1]);
            Console.WriteLine(maxWeight - minWeight);
        }
        catch (Exception e)
        {
            Console.WriteLine($"Error reading file: {e.Message}");
        }
    }
}
