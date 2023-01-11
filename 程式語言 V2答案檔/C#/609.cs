using System;

public class TQC609
{
    public static void Main(string[] args)
    {
        int[] monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string[] inputs = Console.ReadLine().Split(' ');
        int year = Convert.ToInt32(inputs[0]);
        int month = Convert.ToInt32(inputs[1]);
        int day = Convert.ToInt32(inputs[2]);
        int answer = 0;

        if (IsInputIllegal(year, month, day)) { // input is illegal, print error
            Console.WriteLine("error");
        }
        else {
            for (int i = 0; i < month - 1; i++) {
                answer += monthDays[i];
            }
            answer += day + (IsLeapYear(year) && month >= 3 ? 1 : 0);
            Console.WriteLine(answer);
        }
    }

    // check the input is illegal or not
    public static bool IsInputIllegal(int year, int month, int day) {
        int[] monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (IsLeapYear(year)) {
            monthDays[1] += 1;
        }
        
        if (day > monthDays[month - 1])
            return true;
        else
            return false;
    }

    public static bool IsLeapYear(int year) {
        if (year % 400 == 0)
            return true;
        else if ((year % 4 == 0) && (year % 100 != 0))
            return true;
        else
            return false;
    }
}