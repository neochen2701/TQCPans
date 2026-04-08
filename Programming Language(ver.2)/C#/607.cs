using System;
using System.Collections.Generic;
using System.Linq;

public class TQC607
{
    public static void Main(string[] args)
    {
        string input = Console.ReadLine();
        List<string> cards = new List<string> ();
        cards = input.Split(new char[] { ' ' }).ToList<string>();
        char[] colors = { 'C', 'D', 'H', 'S' };
        if (Array.IndexOf(colors, cards[0][0]) > Array.IndexOf(colors, cards[1][0]))
        {
            Console.WriteLine($"{cards[0]} > {cards[1]}");
        }
        else if (Array.IndexOf(colors, cards[0][0]) < Array.IndexOf(colors, cards[1][0]))
        {
            Console.WriteLine($"{cards[0]} < {cards[1]}");
        }
        else
        {
            int num0 = Convert.ToInt32(cards[0].Substring(1, cards[0].Length - 1));
            int num1 = Convert.ToInt32(cards[1].Substring(1, cards[1].Length - 1));
            if (num0 > num1) Console.WriteLine($"{cards[0]} > {cards[1]}");
            else if (num0 < num1) Console.WriteLine($"{cards[0]} < {cards[1]}");
            else Console.WriteLine($"{cards[0]} = {cards[1]}");
        }
    }
}