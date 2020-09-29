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
                double x = 0, y = 0;
                x = Convert.ToDouble(Console.ReadLine());
                y = Convert.ToDouble(Console.ReadLine());
                if (x==0.0  && y ==0.0)
                {
                    Console.Write("(" + x.ToString() + "," + y.ToString() +") origin");
                }else if (x == 0.0 && y != 0.0)
                {
                    Console.Write("(" + x.ToString() + "," + y.ToString() + ") Y");
                }
                else if (x != 0.0 && y == 0.0)
                {
                    Console.Write("(" + x.ToString() + "," + y.ToString() + ") X");
                }
                else if (x > 0.0 && y > 0.0)
                {
                    Console.Write("(" + x.ToString() + "," + y.ToString() + ") 1");
                }
                else if (x < 0.0 && y < 0.0)
                {
                    Console.Write("(" + x.ToString() + "," + y.ToString() + ") 3");
                }
                else if (x > 0.0 && y < 0.0)
                {
                    Console.Write("(" + x.ToString() + "," + y.ToString() + ") 4");
                }
                else if (x < 0.0 && y > 0.0)
                {
                    Console.Write("(" + x.ToString() + "," + y.ToString() + ") 2");
                }
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }

    }
}
