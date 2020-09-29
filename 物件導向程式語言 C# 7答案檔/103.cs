using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA01
{
    class CSA01
    {
        const double pi = 3.1415926;
        static void Main(string[] args)
        {
            string str1 = Console.ReadLine();
            str1 = str1.Trim() == "" ? "0" : str1;
            double number;
            bool ok = Double.TryParse(str1, out number);
            Console.Write((calCircle(Convert.ToDouble(number)).ToString("f4")));
            Console.ReadKey();
        }
        static double calCircle(double x)
        {
            return x * x * pi;
        }
    }
}
