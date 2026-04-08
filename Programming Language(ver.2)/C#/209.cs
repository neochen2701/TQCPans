using System;

public class TQC209
{
    public static void Main(string[] args)
    {
        int input;
        input = int.Parse(Console.ReadLine());
        if (input == 0) 
            PrintHorizontalMultiplicationTable();
        else if (input == 1)
            PrintVerticalMultiplicationTable();
        else
            Console.WriteLine("error");
    }

    public static void PrintHorizontalMultiplicationTable() {
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++) {
                Console.Write(String.Format("{0} x {1} = {2}\t", i, j, i * j));
            }
            Console.WriteLine("");
        }
    }

    public static void PrintVerticalMultiplicationTable() {
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++) {
                Console.Write(String.Format("{0} x {1} = {2}\t", j, i, i * j));
            }
            Console.WriteLine("");
        }
    }
}