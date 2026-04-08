using System;
class Class1 {
    public static int compute (int[] inputs) {
        if (inputs[1] == 1) {
            return inputs[0] + inputs[2];
        }
        else {
            return inputs[0] * inputs[2];
        }
    }
    static void Main() {
        int [] inputs = new int[3];
      	inputs[0] = Convert.ToInt32(Console.ReadLine());
        inputs[1] = Convert.ToInt32(Console.ReadLine());
        inputs[2] = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine(compute(inputs));
    }
}