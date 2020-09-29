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
            try
            {
                int number = Convert.ToInt32(Console.ReadLine());
                if (number < 1 || number > 20) { throw new Exception(); }
                long x = compute(number);
                
                Console.Write(x.ToString());
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
        static long compute(long num)
        {
            if (num == 1 )
                return 1;
            return compute(num - 1) * num;
        }
  
    }
}
