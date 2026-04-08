using System;

public class TQC310
{
    public static void Main(string[] args)
    {
        int number;
        number = int.Parse(Console.ReadLine());

        Console.WriteLine(compute(number));
    }

    public static int compute(int number) {
        int sum = 0;
        for (int i = 1; i < number; i++) {
            if (IsArmstrongNumber(i)) {
                sum += i;
                Console.WriteLine(i);
            }
        }
        return sum;
    }

    public static bool IsArmstrongNumber(int number) {
        int sum = 0;
        string numberString = number.ToString();
        int k = numberString.Length;
        for (int i = 0; i < k; i++) {
            sum += (int)(Math.Pow(numberString[i] - '0', k));
        }
        
        return sum == number;
    }
}