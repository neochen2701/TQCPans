using System;
class Class1
{
    static void Main()
    {
        int[] inputs = new int[10];
        int[] counts = new int[] { 0, 0, 0, 0, 0, 0 };
        int errorCount = 0;
        for (int i = 0; i < 10; i++)
        {
            inputs[i] = Convert.ToInt32(Console.ReadLine());
            if (inputs[i] <= 0 || inputs[i] > 6)
            {
                errorCount += 1;
            }
            else
            {
                counts[inputs[i] - 1] += 1;
            }
        }
        for (int i = 0; i < 6; i++)
        {
            Console.WriteLine($"number{i + 1}:{counts[i]}");
        }
        Console.WriteLine($"error:{errorCount}");
    }
}