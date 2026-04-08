using System;
class Class1 {
    static void Main() {
        int input = Convert.ToInt32(Console.ReadLine());
        int input2 = Convert.ToInt32(Console.ReadLine());
        int input3 = Convert.ToInt32(Console.ReadLine());
        int input4 = Convert.ToInt32(Console.ReadLine());
        int input5 = Convert.ToInt32(Console.ReadLine());
        int input6 = Convert.ToInt32(Console.ReadLine());
        Console.Write($"{input, 10}" + " ");
        Console.Write($"{input2, 10}" + " ");
        Console.WriteLine($"{input3, 10}");
        Console.Write($"{input4, 10}" + " ");
        Console.Write($"{input5, 10}" + " ");
        Console.WriteLine($"{input6, 10}");
        Console.Write($"{input, -10}" + " ");
        Console.Write($"{input2, -10}" + " ");
        Console.WriteLine($"{input3, -10}");
        Console.Write($"{input4, -10}" + " ");
        Console.Write($"{input5, -10}" + " ");
        Console.WriteLine($"{input6, -10}");
    }
}