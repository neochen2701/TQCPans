using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void CalculateSumAvg(List<List<string>> inputs)
    {
        foreach (var studentScores in inputs)
        {
            var scores = studentScores.Skip(1).Select(int.Parse).ToList();
            var sumScore = scores.Sum();
            var avgScore = (double)sumScore / scores.Count;
            studentScores.Add(sumScore.ToString());
            studentScores.Add($"{avgScore:F2}");
        }
    }

    static void Main(string[] args)
    {
        var inputs = new List<List<string>>();
        string inputStr;
        
        while ((inputStr = Console.ReadLine()) != "END")
        {
            var inputScores = inputStr.Split().ToList();
            inputs.Add(inputScores);
        }

        CalculateSumAvg(inputs);

        inputs.Sort((x, y) => -float.Parse(x[^2]).CompareTo(float.Parse(y[^2])));

        foreach (var studentScores in inputs)
        {
            Console.WriteLine(string.Join(" ", studentScores));
        }
    }
}
