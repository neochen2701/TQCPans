using System;

public class TQC104
{
    public static void Main(string[] args)
    {
        float a, b, total;
        a =  float.Parse(Console.ReadLine());
        b =  float.Parse(Console.ReadLine());

        total = a + b;
        int total_2 = (int)((total + 0.005) * 100);

        Console.Write("total=" + (total_2/100.0).ToString("f2"));
    }
}