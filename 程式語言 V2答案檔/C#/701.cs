using System;

public class TQC701
{
    public static void Main(string[] args)
    {
        int a = Convert.ToInt32(Console.ReadLine());
        int b = Convert.ToInt32(Console.ReadLine());
        int c = Convert.ToInt32(Console.ReadLine());
        double s = (a + b + c) / 2.0;
        double result = Math.Sqrt(s * (s - a) * (s - b) * (s - c));
        Console.WriteLine("{0:N2}", result);
    }
}