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
            int x1, x2, x3;
            Int32.TryParse(Console.ReadLine(), out x1);
            Int32.TryParse(Console.ReadLine(), out x2);
            Int32.TryParse(Console.ReadLine(), out x3);
            x1 = x1 > 100 ? 100 : x1;
            x2 = x2 > 100 ? 100 : x2;
            x3 = x3 > 100 ? 100 : x3;
            x1 = x1 < 0 ? 0 : x1;
            x2 = x2 < 0 ? 0 : x2;
            x3 = x3 < 0 ? 0 : x3;
            int avg = (x1 + x2 + x3) / 3;

            if (avg < 60)
            {
                Console.Write("failed:" + avg);
            }
            if (avg >= 60 && avg < 100)
            {
                Console.Write("pass:" + avg);
            }
            if (avg == 100)
            {
                Console.Write("full mark:" + avg);
            }
            Console.ReadKey();
        }

    }
}
