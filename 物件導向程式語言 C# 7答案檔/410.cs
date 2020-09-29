using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA04
{
    class CSA04
    {
        static string[] birthday = { "1980/1/11", "1985/3/2", "1985/12/3","1986/6/3","1986/11/14","1987/2/2","1987/8/1","1987/10/12","1987/9/3","1987/8/1","1987/4/12","1988/1/3","1987/5/6","1987/6/7","1987/8/19","1987/6/13","1987/10/9","1986/4/8","1987/5/15","1987/2/19","1987/3/15", "1987/3/11", "1987/3/31" };
        static void Main(string[] args)
        {
            try
            {
                int mm = Convert.ToInt32(Console.ReadLine());
                if(mm<1 || mm > 12) { throw new Exception(); }
                int pers = 0;
                for(int i = 0; i <= birthday.Length - 1; i++)
                {
                    DateTime bday = Convert.ToDateTime(birthday[i].ToString());
                    
                    if(bday.Month == mm )
                    {
                        pers += 1;
                    }
                }

                Console.Write(pers);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }
    }
}
