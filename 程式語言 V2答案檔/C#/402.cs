using System;

public class TQC402
{
    public static void Main(string[] args)
    {
        string str1, str2;
        int n;
        str1 = Console.ReadLine();
        str2 = Console.ReadLine();
        n = int.Parse(Console.ReadLine());

        if (n > str1.Length || n > str2.Length) {
            Console.WriteLine("error");    
        }
        else {
            string subString1 = str1.Substring(0, n);
            string subString2 = str2.Substring(0, n);
            int compare = strncmp(str1, str2, n);
            if (compare == -1)
                Console.WriteLine(str1 + " < " + str2);
            else if (compare == 0)
                Console.WriteLine(str1 + " = " + str2);
            else if (compare == 1)
                Console.WriteLine(str1 + " > " + str2);
        }
    }

    public static int strncmp(string str1, string str2, int n) {
        for (int i = 0; i < n; i++) {
            if (str1[i] < str2[i])
                return -1;
            else if (str1[i] > str2[i])
                return 1;
        }
        return 0;
    }
}