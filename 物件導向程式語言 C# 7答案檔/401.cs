using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

namespace CSA04
{
    class CSA04
    {
        static void Main(string[] args)
        {
            try
            {
                DateTime dt = DateTime.ParseExact(Console.ReadLine(), "yyyyMMdd", null);

                
                    Console.Write(dt.ToString("yyyy/MM/dd") + " " + dt.ToString("ddd", CultureInfo.InvariantCulture));
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }



    }
}
