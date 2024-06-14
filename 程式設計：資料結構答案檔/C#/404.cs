using System;
using System.Collections.Generic;
using System.Linq;

class Vertex
{
    public int Id { get; set; }
    public List<int> Neighbors { get; set; }

    public Vertex(int id)
    {
        Id = id;
        Neighbors = new List<int>();
    }
}

class Graph
{
    public List<Vertex> Vertices { get; set; }

    public Graph()
    {
        Vertices = new List<Vertex>();
    }

    public void AddEdge(int u, int v)
    {
        var vertexU = Vertices.Find(vert => vert.Id == u) ?? new Vertex(u);
        if (!Vertices.Contains(vertexU))
        {
            Vertices.Add(vertexU);
        }
        vertexU.Neighbors.Add(v);

        var vertexV = Vertices.Find(vert => vert.Id == v) ?? new Vertex(v);
        if (!Vertices.Contains(vertexV))
        {
            Vertices.Add(vertexV);
        }
        vertexV.Neighbors.Add(u);
    }
}

class Program
{
    static void FindAllPaths(Graph graph, int start, int end, List<int> path, List<List<int>> allPaths)
    {
        path.Add(start);
        if (start == end)
        {
            allPaths.Add(new List<int>(path));
        }
        else
        {
            var vertex = graph.Vertices.FirstOrDefault(v => v.Id == start);
            if (vertex != null)
            {
                foreach (var neighbor in vertex.Neighbors)
                {
                    if (!path.Contains(neighbor))
                    {
                        FindAllPaths(graph, neighbor, end, path, allPaths);
                    }
                }
            }
        }
        path.RemoveAt(path.Count - 1);
    }

    static List<int>? GetMaxPath(List<List<int>> allPaths)
    {
        return allPaths
            .OrderByDescending(path => path.Count)
            .ThenByDescending(path => path.Sum())
            .FirstOrDefault();
    }

    static void Main(string[] args)
    {
        var inputNM = Console.ReadLine().Split(' ');
        int n = int.Parse(inputNM[0]);
        int m = int.Parse(inputNM[1]);

        var graph = new Graph();
        for (int i = 0; i < m; i++)
        {
            var edge = Console.ReadLine().Split(' ');
            graph.AddEdge(int.Parse(edge[0]), int.Parse(edge[1]));
        }

        var inputSE = Console.ReadLine().Split(' ');
        int startN = int.Parse(inputSE[0]);
        int endN = int.Parse(inputSE[1]);

        var path = new List<int>();
        var allPaths = new List<List<int>>();
        FindAllPaths(graph, startN, endN, path, allPaths);

        var maxPath = GetMaxPath(allPaths);
        if (maxPath != null)
        {
            Console.WriteLine(string.Join(" ", maxPath));
        }
    }
}
