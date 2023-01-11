using System;

public class TQC208
{
    public static void Main(string[] args)
    {
        int num;
        num = int.Parse(Console.ReadLine());
        for (int i = 2; i < num; i++) {
            if (IsPrime(i)) {
                Console.Write(i.ToString() + " ");
            }
        }
    }

    public static bool IsPrime(int num) {
        for (int i = 2; i < num; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
}