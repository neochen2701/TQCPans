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
                int x1, x2;
                x1 = Convert.ToInt32(Console.ReadLine());
                x2 = Convert.ToInt32(Console.ReadLine());
                if (x1 < 0 || x1 > 100 || x2 < 0 || x2 > 100)
                {
                    throw new ArgumentException();
                }
                Console.Write(GCD(x1, x2));
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }

        static int GCD(int x1, int x2)
        {
            if (x1 == 0)
            {
                return x2;
            }
            else if (x2 == 0)
            {
                return x1;
            }
            else
            {
                int reminder = x1 % x2;
                return GCD(x2, reminder);
            }
        }
    }
}
