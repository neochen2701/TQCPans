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
                DateTime dt = DateTime.ParseExact(Console.ReadLine(), "yyyyMMdd", null);
                string firstDay = dt.AddDays(1 - Convert.ToInt32(dt.DayOfWeek.ToString("d"))).AddDays(-7).ToString("yyyy/MM/dd");
                string lastDay = Convert.ToDateTime(firstDay).AddDays(6).ToString("yyyy/MM/dd");
                Console.Write("{0}-{1}", firstDay, lastDay);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }
    }
}
