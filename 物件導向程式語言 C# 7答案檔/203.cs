using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA02
{
    class CSA02
    {
        static void Main(string[] args)
        {

            int x1 ,x2,x3;
            Int32.TryParse(Console.ReadLine(), out x1);
            Int32.TryParse(Console.ReadLine(), out x2);
            Int32.TryParse(Console.ReadLine(), out x3);
            print(x1);
            print(x2);
            print(x3);
            Console.ReadKey();
        }

        static void print(int x)
        {
            if (x >= 85 && x <= 100)
            {
                Console.WriteLine("A");
            }
            else if (x >= 60 && x < 85)
            {
                Console.WriteLine("B");
            }
            else if (x < 60)
            {
                Console.WriteLine("C");
            }
        }
    }
}
