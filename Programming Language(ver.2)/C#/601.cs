using System;

public class TQC601
{
    public static void Main(string[] args)
    {
        string data = Console.ReadLine();
        int n = int.Parse(Console.ReadLine());
        char[] dataChars = data.ToCharArray();
        if (n>=0 && n<data.Length)
        {
            char item =  dataChars[n];
            if (item >= 'a' && item <= 'z')
            {
                dataChars[n] = Char.ToUpper(item);
            }
            else if (item >= 'A' && item <= 'Z')
            {
                dataChars[n] = Char.ToLower(item);
            }        
        }
        string newData = new string(dataChars);
        Console.WriteLine($"The letter that was selected is: {dataChars[n]}");
        Console.WriteLine(newData);
    }
}