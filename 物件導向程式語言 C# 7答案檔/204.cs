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

                // swap(x1, x2) if x1 > x2
                int tmp;
                if (x1 > x2)
                {
                    tmp = x1;
                    x1 = x2;
                    x2 = tmp;
                }

                // check the boundary conditions
                if (x1 <= 0 || x2 > 100)
                {
                    throw new ArgumentException();
                }

                // 1 is not a prime
                bool foundFactor;
                for (int n = Math.Max(x1, 2); n <= x2; n++)
                {
                    foundFactor = false;
                    for (int k = 2; k < n; k++)
                    {
                        if (n % k == 0)
                        {
                            foundFactor = true;
                            break; // it is not a prime
                        }
                    }
                    if (!foundFactor)
                    {
                        Console.WriteLine(n);
                    }
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
