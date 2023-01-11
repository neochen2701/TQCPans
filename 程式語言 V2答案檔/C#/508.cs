using System;

public class TQC508
{
    public static void Main(string[] args)
    {
        string binaryString1, binaryString2;
        int binary1, binary2;
        binaryString1 = Console.ReadLine();
        binaryString2 = Console.ReadLine();
        binary1 = Convert.ToInt32(binaryString1, 2);
        binary2 = Convert.ToInt32(binaryString2, 2);
        int sum = binary1 + binary2;
        string binarySumString = Convert.ToString(sum, 2).PadLeft(8, '0');

        Console.WriteLine(String.Format("{0} + {1} = {2}", binary1, binary2, sum));
        Console.WriteLine((binarySumString.Length > 8 ? "11111111" : binarySumString));
    }
}