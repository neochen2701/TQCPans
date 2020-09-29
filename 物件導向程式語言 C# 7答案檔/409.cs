using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Globalization;

namespace CSA04
{
    class CSA04
    {
        static void Main(string[] args)
        {
            try
            {
                //TODO
                DateTime startDay = DateTime.ParseExact(
                    Console.ReadLine(), "yyyyMMdd",
                    CultureInfo.InvariantCulture);
                DateTime endDay = DateTime.ParseExact(
                    Console.ReadLine(), "yyyyMMdd",
                    CultureInfo.InvariantCulture);

                // checking the arguments
                if (startDay > endDay)
                {
                    throw new ArgumentException(
                        "startDay should be less than endDay");
                }

                int years = endDay.Year - startDay.Year;
                int months = endDay.Month - startDay.Month;
                int days = endDay.Day - startDay.Day;

                if (days < 0)
                {
                    months -= 1;

                    // newMonth: the first day of the next month (from startDay)
                    // In this way, we could calculate the diff
                    // without concidering the leap month, 30/31 days
                    int newMonth_Year = startDay.Year;
                    int newMonth_Month = startDay.Month + 1;
                    int newMonth_Day = startDay.Day;
                    if (newMonth_Month > 12)
                    {
                        newMonth_Month = 1;
                        newMonth_Year += 1;
                    }
                    DateTime newMonthDay = new DateTime(
                        newMonth_Year, newMonth_Month, newMonth_Day);
                    days = (newMonthDay - startDay).Days;
                    days += (endDay.Day - newMonthDay.Day);
                }
                if (months < 0)
                {
                    months += 12;
                    years -= 1;
                }
                Console.Write("{0}y:{1}m:{2}d",years, months, days);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }
    }
}
