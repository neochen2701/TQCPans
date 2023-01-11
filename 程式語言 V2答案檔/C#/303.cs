using System;
class Class1 {
    public static int compute (int input) {
        for (int i=2; i<=Math.Sqrt(input); i++) {
            if (input % i == 0)  return 0;
        }
        return 1;
    }
    static void Main() {
      	int input = Convert.ToInt32(Console.ReadLine());
        if (compute(input) == 1) {
            Console.WriteLine($"{input} is a prime number");
        }
        else {
            Console.WriteLine($"{input} is not a prime number");
        }
    }
}