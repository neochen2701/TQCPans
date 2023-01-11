using System;
class Class1 {
    static void Main() {
      	int input = Convert.ToInt32(Console.ReadLine());
      	int input2 = Convert.ToInt32(Console.ReadLine());
      	double result = Math.Sqrt((input + input2)) ;
	  	Console.Write("result=");
      	Console.WriteLine(String.Format("{0:0.00}", result));
    }
}