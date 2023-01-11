using System;

public class TQC501
{
    public static void Main()
    {
        string input = Console.ReadLine();
        double result_double = Convert.ToDouble(input);
        int result_int = Convert.ToInt32(Math.Floor(result_double));
        Console.Write(input);
        Console.Write(" change to ");
        Console.WriteLine(result_int);
    }
}