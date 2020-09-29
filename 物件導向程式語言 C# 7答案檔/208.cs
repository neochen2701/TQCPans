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
                int x1 = 0;
                x1 = Convert.ToInt32(Console.ReadLine());
                if (x1 > 9) { throw new Exception(); }

                //TODO
                int k;
                for (int i = 1; i <= x1; i++)
                {
                    for (int j = 1; j <= i; j++)
                    {
                        k = i - j + 1;
                        Console.Write("{0}*{1}={2,-4:00}", i, k, i * k);
                    }
                    Console.WriteLine();
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