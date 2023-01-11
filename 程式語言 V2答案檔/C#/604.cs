using System;

public class TQC604
{
    public static void Main(string[] args)
    {
        int[] array = new int[9];
        for (int i = 0; i < 9; i++) {
            array[i] = int.Parse(Console.ReadLine());
        }

        Sort(array);

        int sum = 0;
        for (int i = 0; i < 9; i++) {
            Console.WriteLine(array[i]);
            sum += array[i];
        }
        Console.WriteLine("sum = " + sum.ToString());
    }

    public static void Sort(int[] array) {
        for (int i = 0; i < array.Length; i++) {
            int minIndex = i;
            for (int j = i + 1; j < array.Length; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            //swap
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}