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
            int x1, x2, x3;
            Int32.TryParse(Console.ReadLine(), out x1);
            Int32.TryParse(Console.ReadLine(), out x2);
            Int32.TryParse(Console.ReadLine(), out x3);
            x1 = x1 < 0 ? 0 : x1;
            x2 = x2 < 0 ? 0 : x2;
            x3 = x3 < 0 ? 0 : x3;
            int total = x1 + (x2 * 5) + (x3 * 10);

            Console.Write(total.ToString("#,###"));
            Console.ReadKey();
        }



    }
}
