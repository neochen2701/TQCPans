using System;

public class TQC108
{
    public static void Main(string[] args)
    {
        const double pi = 3.1415;
        int d;
        double r, area;
        
        d = int.Parse(Console.ReadLine());
        r = d / 2.0;
        area =  r * r * pi;

        double r_2 = ((int)((r + 0.005) * 100)) / 100.0;
        double area_2 = ((int)((area + 0.00005) * 10000)) / 10000.0;

        Console.WriteLine(String.Format("{0, -10}", d));
        Console.WriteLine(String.Format("{0, -10:F2}", r_2));
        Console.WriteLine(String.Format("{0, -10:F4}", area_2));
    }
}