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
            int x1, x2, x3,x4;
            Int32.TryParse(Console.ReadLine(), out x1);
            Int32.TryParse(Console.ReadLine(), out x2);
            Int32.TryParse(Console.ReadLine(), out x3);
            Int32.TryParse(Console.ReadLine(), out x4);
            x1 = x1 < 0 ? 0 : x1;
            x2 = x2 < 0 ? 0 : x2;
            x3 = x3 < 0 ? 0 : x3;
            x4 = x4 < 0 ? 0 : x4;
            int max= Math.Max(Math.Max(x1, x2), Math.Max(x3, x4));
            int min = Math.Min(Math.Min(x1, x2), Math.Min(x3, x4));
            print(min, max);
        }
        static void print(int min,int max)
        {//min=>smallest，max=>largest
            Console.WriteLine("smallest:" + min.ToString());
            Console.Write("largest:" + max.ToString());
            Console.ReadKey();
        }
    }
}
