using System;
using System.Linq;

public class TQC603
{
    public static void Main(string[] args)
    {
        string input = Console.ReadLine();
        int[] size = input.Split(new char[] { ' ' }).Select(i => int.Parse(i)).ToArray(); 
        int[,] arr = new int[size[0], size[1]];
        
        for (int i = 0; i < size[0]; i++)
        {
            input = Console.ReadLine();
            int[] data = input.Split(new char[] { ' ' }).Select(r => int.Parse(r)).ToArray();
            for (int j = 0; j < data.Length; j++)
            {
                arr[i,j] = data[j];
            }
        }

        for (int i = 0; i < size[0]; i++)
        {
            for (int j = 0; j < size[1]; j++)
            {
                Console.Write(arr[i,j]);
                if (j != size[1] - 1) Console.Write(",");
            }
            Console.WriteLine();
        }
    }
}
