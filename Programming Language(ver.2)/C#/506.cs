using System;

public class TQC506
{
    public static void Main(string[] args)
    {
        int number;
        number = int.Parse(Console.ReadLine());

        if (IsPrime(number))
            Console.WriteLine("-1");
        else {
            string result = "";
            int primeFactor = 2;
            while (number > 1) {
                if (number % primeFactor == 0) {
                    number = number / primeFactor;
                    result += primeFactor.ToString() + "*";
                }
                else {
                    while (!IsPrime(++primeFactor));
                }
            }
            Console.WriteLine(result.Substring(0, result.Length - 1));
        }
    }

    public static bool IsPrime(int number) {
        if (number == 2)
            return true;
        if (number % 2 == 0)
            return false;
        for (int i = 3; i < number; i += 2) {
            if (number % i == 0)
                return false;
        }
        return true;
    }
}