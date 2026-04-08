using System;

public class TQC206
{
    public static void Main(string[] args)
    {
        int start, end;
        int result = 0;
        start = int.Parse(Console.ReadLine());
        end = int.Parse(Console.ReadLine());
        
        if (start % 2 == 0)
            start += 1;

        for (int num = start; num <= end; num += 2) {
            result += num;
        }
        Console.WriteLine(result);
    }
}