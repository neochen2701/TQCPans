using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA04
{
    class CSA04
    {
        static void Main(string[] args)
        {
            try
            {
                DateTime dt1 = DateTime.ParseExact(Console.ReadLine(), "yyyyMMdd", null);
                DateTime dt2 = DateTime.ParseExact(Console.ReadLine(), "yyyyMMdd", null);
                TimeSpan ts = dt2 - dt1;
                double days = Math.Abs(ts.TotalDays);
                Console.Write(days);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }



    }
}
