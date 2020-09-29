using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace CSA01
{
    class CSA01
    {
        static void Main(string[] args)
        {
            double x1;

            if (double.TryParse(Console.ReadLine(), out x1))
            {
                Console.Write(f(x1).ToString("F4"));
            }
            else
            {
                Console.Write("error");
            }

            Console.ReadKey();
        }

        static double f(double x)
        {
            return 2 * Math.Pow(x, 3) + 3 * x - 1;
        }

    }
}
