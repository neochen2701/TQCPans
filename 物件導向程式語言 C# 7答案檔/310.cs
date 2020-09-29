using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA03
{
    class CSA03
    {
        static void Main(string[] args)
        {
            //TODO
            int num, result;

            try
            {
                num = int.Parse(Console.ReadLine());
                if (num == 0)
                {
                    throw new ArgumentException("num could not be zero");
                }

                num = Math.Abs(num);
                result = compute(num);
                Console.Write(result);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }
        // ==================================================
        // Please write your code in the specified Method
        // Do NOT change the method name, type of parameter
        // ==================================================
        static int compute(int n)
        {
            //TODO
            if (n == 1)
            {
                return 2;
            }
            else
            {
                return compute(n - 1) + (3 * n);
            }
        }

    }
}
