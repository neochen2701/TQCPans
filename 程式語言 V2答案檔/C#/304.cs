using System;

public class TQC304
{
    public static void Main(string[] args)
    {
        int[] numbers = new int[6];
        for (int i = 0; i < 6; i++) {
            numbers[i] = int.Parse(Console.ReadLine());
        }
        
        Console.WriteLine(compute(numbers));
    }

    public static int compute(int[] numbers) {
        int count = 0;
        for (int i = 0; i < numbers.Length; i++) {
            if (numbers[i] % 3 == 0)
                count++;
        }
        return count;
    }
}