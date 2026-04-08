using System;

public class TQC503
{
    public static void Main()
    {
        string input_a = Console.ReadLine();
        string input_b = Console.ReadLine();
        int a = Convert.ToInt32(input_a);
        int b = Convert.ToInt32(input_b);
        double result_double;
        for (double i = 1; i < a; i++)
        {
            result_double = Math.Sqrt(i);
            if (Convert.ToInt32(result_double) == result_double)
            {
                result_double = Math.Pow(result_double, b);
                Console.WriteLine(result_double);
            }
        }
    }
}