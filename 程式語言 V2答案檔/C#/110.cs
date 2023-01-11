using System;

public class TQC110
{
    public static void Main(string[] args)
    {
        int a, b, c;
        a = int.Parse(Console.ReadLine());
        b = int.Parse(Console.ReadLine());
        c = int.Parse(Console.ReadLine());

        Console.WriteLine((a >= 60 && a < 100) ? "1" : "0");
        Console.WriteLine(((b + 1) / 10.0).ToString("f2"));
        Console.WriteLine((a >= c) ? a.ToString() : c.ToString());
    }
}