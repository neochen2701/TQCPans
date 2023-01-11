using System;
class Class1 {
    public static int compute (int[] inputs) {
        int max = -99999;
        for (int i=0; i<5; i++) {
            if (inputs[i] > max) {
                max = inputs[i];
            }
        }
        return max;
    }
    static void Main() {
        int [] inputs = new int[5];
        for (int i=0; i<5; i++) {
            inputs[i] = Convert.ToInt32(Console.ReadLine());
        }
        Console.WriteLine(compute(inputs));
    }
}