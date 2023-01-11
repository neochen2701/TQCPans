using System;

public class TQC308
{
    public static void Main(string[] args)
    {
        int n;
        n = int.Parse(Console.ReadLine());

        for (int i = n; i >= 1; i--) {
            Console.WriteLine(String.Format("fib({0})={1}", i, compute(i)));
        }
    }

    public static int compute(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        
        return compute(n - 1) + compute(n - 2);
    }
}