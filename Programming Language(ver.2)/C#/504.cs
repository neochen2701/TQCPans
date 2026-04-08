using System;

public class TQC504
{
    public static void Main(string[] args)
    {
        string number;
        number = Console.ReadLine();
        Console.WriteLine(IsPalindrome(number) ? "Yes" : "No");
    }

    public static bool IsPalindrome(string number) {
        for (int i = 0; i < number.Length; i++) {
            if (number[i] != number[number.Length - i - 1])
                return false;
        }
        return true;
    }
}