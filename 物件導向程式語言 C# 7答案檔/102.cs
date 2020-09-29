using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA01
{
    class CSA01
    {
        static void Main(string[] args)
        {
            string line;
            int num1, num2, sum;

            line = Console.ReadLine();
            try
            {
                num1 = int.Parse(line);
                num1 = num1 % 2 == 0 ? num1 : 0;
            }
            catch (FormatException)
            {
                num1 = 0;
            }

            line = Console.ReadLine();
            try
            {
                num2 = int.Parse(line);
                num2 = num2 % 2 == 0 ? num2 : 0;
            }
            catch (FormatException)
            {
                num2 = 0;
            }

            sum = num1 + num2;
            Console.Write(sum);
            Console.ReadKey();
        }
    }
}
