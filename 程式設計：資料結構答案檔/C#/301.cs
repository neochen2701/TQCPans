using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Player
{
    public int Id { get; set; }
    public string Name { get; set; }
    public int Level { get; set; }
    public int Score { get; set; }
}

class Program
{
    static void Main()
    {
        var filePath = "read.csv";
        var rawData = ReadCsvFile(filePath);

        if (!rawData.Any())
        {
            Console.WriteLine("Error reading CSV file or file is empty.");
            return;
        }

        List<Player> players = ParsePlayerData(rawData);

        if (!int.TryParse(Console.ReadLine(), out int n))
        {
            Console.WriteLine("Invalid input");
            return;
        }

        DisplaySortedPlayerData(players, n);
    }

    static List<string[]> ReadCsvFile(string filePath)
    {
        var data = new List<string[]>();
        try
        {
            using (var reader = new StreamReader(File.OpenRead(filePath)))
            {
                while (!reader.EndOfStream)
                {
                    var line = reader.ReadLine();
                    var values = line.Split(',');
                    data.Add(values);
                }
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error reading CSV file: {ex.Message}");
        }
        return data;
    }

    static List<Player> ParsePlayerData(List<string[]> rawData)
    {
        return rawData.Skip(1)
            .Select(data => new Player()
            {
                Id = int.Parse(data[0]),
                Name = data[1],
                Level = int.Parse(data[2]),
                Score = int.Parse(data[3])
            }).ToList();
    }

    static void DisplaySortedPlayerData(List<Player> players, int n)
    {
        if (n > players.Count)
        {
            Console.WriteLine("Exceeds data upper limit");
            return;
        }

        var sortedPlayers = players.OrderByDescending(p => p.Score).ThenByDescending(p => p.Id).Take(n);

        int rank = 1;
        foreach (var player in sortedPlayers)
        {
            Console.WriteLine($"{rank} | {player.Id} | {player.Name} | {player.Level} | {player.Score}");
            rank++;
        }
    }
}
