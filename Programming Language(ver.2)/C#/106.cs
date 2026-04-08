using System;

public class TQC106
{
    public static void Main(string[] args)
    {
        int x1, y1, x2, y2; 
        x1 = int.Parse(Console.ReadLine());
        y1 = int.Parse(Console.ReadLine());
        x2 = int.Parse(Console.ReadLine());
        y2 = int.Parse(Console.ReadLine());

        double x = (x1 - x2) * (x1 - x2);
        double y = (y1 - y2) * (y1 - y2);
        
        double result = Math.Sqrt(x + y);
        result = ((int)((result + 0.005) * 100)) / 100.0;

        Console.Write(result.ToString("f2"));
    }
}