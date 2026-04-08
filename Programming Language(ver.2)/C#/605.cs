using System;
using System.Collections.Generic;

public class TQC605
{
    public static void Main(string[] args)
    {
        List<int> listNum = new List<int>();
        for (int i = 0; i < 6; i++)
        {
            string input = Console.ReadLine();
            listNum.Add(Convert.ToInt32(input));
        }
        listNum.Sort();
        int sum1 = listNum[0] + listNum[1] + listNum[2];
        int sum2 = listNum[3] + listNum[4] + listNum[5];
        Console.WriteLine(sum2 - sum1);
    }
}