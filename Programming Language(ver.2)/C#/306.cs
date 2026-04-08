using System;

public class TQC306
{
    public static void Main(string[] args)
    {
        int n;
        n = int.Parse(Console.ReadLine());

        Console.WriteLine(String.Format("{0}!={1}", n, compute(n)));
    }

    public static int compute(int n) {
        if (n == 0)
            return 1;
        return n * compute(n - 1);
    }
}