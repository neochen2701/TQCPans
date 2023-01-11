using System;

public class TQC309
{
    public static void Main(string[] args)
    {
        int[] numberArray = new int[6];
        for (int i = 0; i < 6; i++) {
            numberArray[i] = int.Parse(Console.ReadLine());
        }

        double mininumFraction = compute(numberArray);
        Console.WriteLine(mininumFraction.ToString("f3"));
    }

    public static double compute(int[] numberArray) {
        double min = 1000.00;
        int halfLength = numberArray.Length / 2;
        for (int i = 0; i < halfLength; i++) {
            min = Math.Min(min, ((double)numberArray[i] / (double)numberArray[i + halfLength]));
        }
        return min;
    }
}