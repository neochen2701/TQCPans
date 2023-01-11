using System;
class Class1 {
    public static void compute (int[] inputs) {
        for (int i=0; i<inputs[1]; i++) {
            for (int j=0; j<inputs[0]; j++) {
                Console.Write("*");
            }
            Console.WriteLine("");
        }
    }
    static void Main() {
        int [] inputs = new int[2];
      	inputs[0] = Convert.ToInt32(Console.ReadLine());
        inputs[1] = Convert.ToInt32(Console.ReadLine());
        compute(inputs);
        Console.WriteLine(inputs[0] * inputs[1]);
    }
}