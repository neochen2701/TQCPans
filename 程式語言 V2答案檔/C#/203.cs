using System;
class Class1 {
    static void Main() {
      	int input = Convert.ToInt32(Console.ReadLine());
        switch (input){
            case 1:
                Console.WriteLine("one");
                break;
            case 2:
                Console.WriteLine("two");
                break;
            case 3:
                Console.WriteLine("three");
                break;
            case 4:
                Console.WriteLine("four");
                break;
            default:
                Console.WriteLine("error");
                break;
        }
    }
}