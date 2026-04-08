using System;

public class TQC608
{
    public static void Main(string[] args)
    {
        long baseBag = 0;
        for(int i = 0; i < 10; i++) {
            int num = int.Parse(Console.ReadLine());
            if (num > 0) {
                baseBag = baseBag << num;
                baseBag += (1 << (num - 1));
            }
        }
        
        string scoreString = Convert.ToString(baseBag, 2);
        int score = 0;
        for (int i = 0; i < scoreString.Length - 3; i++) {
            if (scoreString[i] == '1')
                score += 1;
        }
        Console.WriteLine("score = " + score.ToString());
    }
}