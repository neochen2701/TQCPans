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
            try
            {
                int x1 = Convert.ToInt32(Console.ReadLine());
                if (x1 % 2 == 0)
                {
                    iseven(x1);
                }
                else
                {
                    isodd(x1);
                }
            }
            catch
            {
                Console.Write("error");
            }
            
            Console.ReadKey();
        }

        static void isodd(int x)
        {
            Console.Write(x + " is an odd number.");
        }
        static void iseven(int x)
        {
            Console.Write(x + " is an even number.");
        }
    }
}
