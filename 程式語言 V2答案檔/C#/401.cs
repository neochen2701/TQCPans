using System;

public class TQC401
{
    public static void Main()
    {
        string input1 = Console.ReadLine();
        string input2 = Console.ReadLine();
        Console.WriteLine(input1.Length);
        Console.WriteLine(input2.Length);
        Console.WriteLine(String.Concat(input1, input2));
    }
}