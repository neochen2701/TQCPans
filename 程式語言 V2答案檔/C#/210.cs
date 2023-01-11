using System;

public class TQC210
{
    public static void Main(string[] args)
    {
        int a, b, gcd, lcm;
        a = int.Parse(Console.ReadLine());
        b = int.Parse(Console.ReadLine());
        gcd = ComputeGCD(a, b);
        lcm = ComputeLCM(a, b, gcd);

        Console.WriteLine(gcd);
        Console.WriteLine(lcm);
    }

    public static int ComputeGCD(int a, int b) {
        if (b == 0)
            return a;
        return ComputeGCD(b, a % b);
    }

    public static int ComputeLCM(int a, int b, int gcd) {
        return Math.Abs(a * b) / gcd;
    }
}