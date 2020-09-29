using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA03
{
    class CSA03
    {
        static String weeks = "Mon Tus Wed Thr Fri Sat Sun";
        static void Main(string[] args)
        {
            try
            {
                String[] week = weeks.Split(' ');
                int x = Convert.ToInt32(Console.ReadLine());
                Console.Write(week[x].ToString());
            }
            catch
            {
                Console.Write("error");
            }
            
            
            Console.ReadKey();
        }



    }
}
