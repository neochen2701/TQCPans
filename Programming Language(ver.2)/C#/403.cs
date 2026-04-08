using System;

class TQC403
{
    static void Main()
    {
        char[] arr = new char[100];
        string input = Console.ReadLine();
        arr = input.ToCharArray(0, input.Length);
        for (int i=0; i<input.Length; i++) {
            if (Char.IsLower(arr[i]) == true) {
                arr[i] = Char.ToUpper(arr[i]);
            }
            else {
                arr[i] = Char.ToLower(arr[i]);
            }
        }
        Console.WriteLine(arr);    
    }
}