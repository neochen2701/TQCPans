using System;

public class TQC204
{
    public static void Main(string[] args)
    {
        int a, b;
        string opt;
        a = int.Parse(Console.ReadLine());
        b = int.Parse(Console.ReadLine());
        opt = Console.ReadLine();
        
        if (opt == "+") {
            Console.WriteLine(String.Format("{0}+{1}={2}", a, b, a + b));
        }
        else if (opt == "-") {
            Console.WriteLine(String.Format("{0}-{1}={2}", a, b, a - b));
        }
        else if (opt == "*") {
            Console.WriteLine(String.Format("{0}*{1}={2}", a, b, a * b));
        }
        else {
            Console.WriteLine("error");
        }
    }
}