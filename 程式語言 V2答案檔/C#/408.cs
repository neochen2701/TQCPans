using System;

public class TQC408
{
    public static void Main(string[] args)
    {
        string inputStr1;
        string inputStr2;
        inputStr1 = Console.ReadLine();
        inputStr2 = Console.ReadLine();

        if (ValidInputLength(inputStr1) && ValidInputLength(inputStr2)) {
            Console.WriteLine(inputStr1.Length);
            Console.WriteLine(inputStr2.Length);
            Console.WriteLine(ReverseString(inputStr2) + ReverseString(inputStr1));
        }
        else {
            Console.WriteLine("error");
        }
    }

    public static bool ValidInputLength(string str) {
        return str.Length > 3 && str.Length <= 20;
    }

    public static string ReverseString(string str) {
        string result = "";
        for (int i = str.Length - 1; i >= 0; i--) {
            result += str[i];
        }
        return result;
    }
}