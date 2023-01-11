using System;

class TQC405
{
    static void Main(string[] args)
    {
        char[] input = new char[3];
        for (int i=0; i<3; i++)
        {
            input[i] = char.Parse(Console.ReadLine());
        }
        string[] lines = System.IO.File.ReadAllLines(@"read.txt");
        for (int i = 0; i < 3; i++)
        {
            char[] arr;
            arr = lines[i].ToCharArray();
            for (int j=0; j < input[i]-'0'; j++)
            {
                arr[j] = input[i];                
            }
            Console.WriteLine(arr);
        }
    }
}