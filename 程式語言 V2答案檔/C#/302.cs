using System;

public class TQC302
{
    public static void Main(string[] args)
    {
        int score;
        score = int.Parse(Console.ReadLine());
        Console.Write(compute(score));
    }

    public static int compute(int score) {
        if (score < 0 || score > 100) 
            return -1;
        
        if (score >= 60)
            return score + 5;

        return score + 10;
    }
}