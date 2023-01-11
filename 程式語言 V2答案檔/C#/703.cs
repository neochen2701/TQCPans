using System;

public class TQC703
{
    public static void Main(string[] args)
    {
        int money = Convert.ToInt32(Console.ReadLine());
        int[] coin = { 50, 10, 5, 1 };
        int[] count = { 0, 0, 0, 0 };
        int i = 0;
        while (money != 0)
        {
            int s = money / coin[i];
            count[i] = s;
            money = money % coin[i];
            i++;
        }
        int hasFirst = 0;
        for (int j = 0; j < count.Length; j++)
        {
            if (count[j] != 0)
            {
                if (hasFirst == 1)
                {
                    Console.Write(" ");
                }
                else
                {
                    hasFirst = 1;
                }
                Console.Write($"{count[j]}*${coin[j]}");
            }
        }
    }
}