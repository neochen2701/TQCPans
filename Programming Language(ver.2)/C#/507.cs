using System;

public class TQC507
{
    public static void Main()
    {
        string ans = Console.ReadLine();
        string guess;
        int a, b;
        for (int i=0; i<3; i++) {
            a = 0;  b = 0;
            guess = Console.ReadLine();
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (guess[j] == ans[k])
                    {
                        if (j == k) a += 1;
                        else b += 1;
                    }
                }
            }
            Console.WriteLine($"{a}A{b}B");
        }
        
    }
}