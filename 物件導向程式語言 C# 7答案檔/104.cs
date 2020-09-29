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
            double x1, x2, y1, y2;
            string str1 = Console.ReadLine();
            bool ok= double.TryParse(str1.Trim().Split(' ')[0].ToString(), out x1);
            ok = Double.TryParse(str1.Trim().Split(' ')[1].ToString(), out y1);
            string str2 = Console.ReadLine();
            ok = Double.TryParse(str2.Trim().Split(' ')[0].ToString(), out x2);
            ok = Double.TryParse(str2.Trim().Split(' ')[1].ToString(), out y2);

            double x = Math.Abs(x1 - x2);
            double y = Math.Abs(y1 - y2);
            Console.Write(Math.Sqrt((x * x) + (y * y)).ToString("f4"));
            Console.ReadKey();
        }
    }
}
