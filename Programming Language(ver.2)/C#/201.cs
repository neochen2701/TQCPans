using System;
class Class1 {
    static void Main() {
      	int input = Convert.ToInt32(Console.ReadLine());
        if (input % 2 == 1) {
            Console.Write("odd");
        }
        else {
            Console.Write("even");
        }
    }
}