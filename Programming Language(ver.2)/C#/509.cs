using System;

public class TQC509
{
    public static void Main(string[] args)
    {
        string inputStr;
        int numberSum = 0;
        inputStr = Console.ReadLine();
        string[] numbers = inputStr.Split('/');
        for (int i = 0; i < numbers.Length; i++) {
            numberSum += Convert.ToInt32(numbers[i]);
        }
        Console.WriteLine(String.Join(" ", numbers));
        Console.WriteLine(numberSum);
    }
}