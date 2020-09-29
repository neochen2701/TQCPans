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
                string[] names = { "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn" };
                string[] dates = { "1/20", "2/19", "3/21", "4/20", "5/21", "6/21", "7/23", "8/23", "9/23", "10/23", "11/22", "12/22" };
                DateTime dt = DateTime.ParseExact(Console.ReadLine(), "yyyyMMdd", null);
                string name = "";
                for (int i = 0; i <= dates.Length - 1; i++)
                {
                    DateTime startDate;
                    DateTime endDate;

                    startDate = Convert.ToDateTime(dt.Year + "/" + dates[i].ToString());
                    if (i == dates.Length - 1)
                    {
                        endDate = Convert.ToDateTime((dt.Year + 1) + "/01/19");
                    }
                    else
                    {
                        endDate = Convert.ToDateTime(dt.Year + "/" + dates[i + 1].ToString()).AddDays(-1);
                    }
                    if (DateTime.Compare(startDate, dt) <= 0 && DateTime.Compare(endDate, dt) >= 0)
                    {
                        name = names[i];
                        break;
                    }
                }
                if (name == "") { name = "Capricorn"; }
                Console.Write(name);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }
    }
}
