using System;

public class TQC202
{
    public static void Main(string[] args)
    {
        int score;
        score = int.Parse(Console.ReadLine());
        
        if (score < 0 || score > 100) {
            Console.WriteLine("error");
        }
        else {
            if (score > 60)
                score += 10;
            else
                score += 5;

            Console.WriteLine(score);
        }
    }
}