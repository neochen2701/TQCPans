using System;
class Class1 {
    static void Main() {
        int input = Convert.ToInt32(Console.ReadLine());
        int input2 = Convert.ToInt32(Console.ReadLine());
        int input3 = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine($"{input}+{input2}+{input3}={input+input2+input3}");
        double avg = (input + input2 + input3) / 3.0;
        Console.WriteLine(String.Format("{0:0.00}", avg));
    }
}