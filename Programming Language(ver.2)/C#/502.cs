using System;

public class TQC502
{
    public static void Main(string[] args)
    {
        int result = 1;
        string prefix = "";
        string number;
        number = Console.ReadLine();
        for (int i = 0; i < number.Length; i++) {
            prefix += number[i] + (i == number.Length - 1 ? "=" : "*");
            result *= Convert.ToInt32(number[i] - '0');
        }
        Console.WriteLine(prefix + result.ToString());
    }
}
