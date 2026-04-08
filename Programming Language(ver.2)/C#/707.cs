using System;
using System.Linq;
using System.Collections.Generic;

public class TQC707
{
    public static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        List<List<int>> num = new List<List<int>>();
        for (int i = 0; i < n; i++)
        {
            List<string> input = Console.ReadLine().Split(new char[] { ' ' }).ToList<string>();
            List<int> tmp = new List<int>();
            tmp.Add(Convert.ToInt32(input[0]));
            tmp.Add(Convert.ToInt32(input[1]));
            tmp.Add(Convert.ToInt32(input[0]) * Convert.ToInt32(input[1]));
            num.Add(tmp);
        }
        IEnumerable<List<int>> result = num.OrderBy(u => u[2]);
        foreach (List<int> r in result)
        {
            Console.WriteLine($"{r[0]}x{r[1]}={r[2]}");
        }
    }
}
