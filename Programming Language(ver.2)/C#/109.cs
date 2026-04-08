using System;

public class TQC109
{
    public static void Main(string[] args)
    {
        int score;
        score = int.Parse(Console.ReadLine());
        if (score < 0 || score > 100) {
            Console.WriteLine("error");
        }
        else {
            // print score is pass or fail
            if (60 <= score && score <= 100) {
                Console.WriteLine("pass");
            }
            else {
                Console.WriteLine("fail");
            }

            // print score is even or odd 
            if (score % 2 == 0) {
                Console.Write("even");
            }
            else {
                Console.Write("odd");
            }
        }
    }
}