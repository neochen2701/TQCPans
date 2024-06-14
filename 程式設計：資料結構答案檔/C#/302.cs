using System;

class BubbleSortDemo
{
    static void Swap(ref int a, ref int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    static void BubbleSort(int[] arr)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            Console.Write(arr[i]);
            if (i < arr.Length - 1)
            {
                Console.Write(" ");
            }
        }
        Console.WriteLine();

        for (int i = 0; i < arr.Length; i++)
        {
            bool swapped = false;
            for (int j = 0; j < arr.Length - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    Swap(ref arr[j], ref arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
            {
                break;
            }

            for (int k = 0; k < arr.Length; k++)
            {
                Console.Write(arr[k]);
                if (k < arr.Length - 1)
                {
                    Console.Write(" ");
                }
            }
            Console.WriteLine();
        }
    }

    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        string[] inputs = Console.ReadLine().Split(' ');
        int[] numbers = new int[n];
        for (int i = 0; i < n; i++)
        {
            numbers[i] = int.Parse(inputs[i]);
        }

        BubbleSort(numbers);
    }
}
