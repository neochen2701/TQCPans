using System;

public class TQC702
{
    public static void Main(string[] args)
    {
        string binaryString = Console.ReadLine();
        Console.WriteLine(Convert.ToInt32(binaryString, 2));
    }
}