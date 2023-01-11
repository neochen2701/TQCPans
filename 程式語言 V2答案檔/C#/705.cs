using System;
using System.Collections.Generic;
using System.Linq;

public class TQC705
{
    public static void Main(string[] args)
    {
        Dictionary<string, int> inventory = new Dictionary<string, int> ();
        List<string> list = new List<string> ();
        int total = 0;
        for (int i=0; i<3; i++)
        {
            List<string> input = Console.ReadLine().Split(new char[] { ' ' }).ToList<string>();
            string name = input[0];
            int count = Convert.ToInt32(input[1]);
            inventory.Add(name, count);
        }
        for (int i = 0; i < 5; i++)
        {
            string input = Console.ReadLine();
            foreach (KeyValuePair<string, int> item in inventory)
            {
                if (String.Compare(input, item.Key, true) == 0)
                {
                    total += item.Value;
                }
            }
        }
        Console.WriteLine(total);
    }
}