using System;

public class TQC505
{
    public static void Main()
    {
        double a = Convert.ToDouble(Console.ReadLine());
        double b = Convert.ToDouble(Console.ReadLine());
        double c = Convert.ToDouble(Console.ReadLine());
        double d = Convert.ToDouble(Console.ReadLine());
        double e = Convert.ToDouble(Console.ReadLine());
        double f = Convert.ToDouble(Console.ReadLine());
        double result = 0;
        result = Math.Abs(a) * Math.Floor(b);
        result += Math.Pow(c, d) * Math.Sqrt(e);
        result += Math.Log10(f);
        string r = result.ToString("0.00");    
        Console.WriteLine(r);
    }
}