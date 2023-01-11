using System;

public class TQC406
{
    public static void Main(string[] args)
    {
        string inputStr;
        string upper = "QWERTYUIOPPASDFGHJKLLZXCVBNMM";
        string lower = "qwertyuioppasdfghjkllzxcvbnmm";
        
        inputStr = Console.ReadLine();
        
        string result = "";
        for (int i = 0; i < inputStr.Length; i++) {
            if (Char.IsLower(inputStr[i])) {
                result += lower[lower.IndexOf(inputStr[i]) + 1];
            }
            else {
                result += upper[upper.IndexOf(inputStr[i]) + 1];
            }
        }

        Console.WriteLine(result);
    }
}
