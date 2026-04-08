using System;

public class TQC102
{
    public static void Main(string[] args)
    {
        int unit;
        double price = 23.34;
        double total;
        unit = int.Parse(Console.ReadLine());
        total = unit * price;
        Console.WriteLine(total.ToString("f2"));
    }
}