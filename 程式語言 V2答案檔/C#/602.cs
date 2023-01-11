using System;

public class TQC602
{
    public static void Main(string[] args)
    {
        string inputStr, upperString = "", lowerString = "";
        inputStr = Console.ReadLine();
        for (int i = 0; i < inputStr.Length; i++) {
            if (Char.IsUpper(inputStr[i])) {
                upperString += inputStr[i];
            }
            else if (Char.IsLower(inputStr[i])) {
                lowerString += inputStr[i];
            }
        }
        Console.WriteLine(upperString);
        Console.WriteLine(lowerString);
        Console.WriteLine(upperString.Length);
    }
}