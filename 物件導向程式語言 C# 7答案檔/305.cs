using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA03
{
    class CSA03
    {
       
        static void Main(string[] args)
        {
            try
            {
                long[] fs = new long[50];
                fs[0] = 0;
                fs[1] = 1;
                for(int i = 2;i <= fs.Length-1; i++)
                {
                    fs[i] = fs[i - 1] + fs[i - 2];
                }
                int index = Convert.ToInt32(Console.ReadLine());
                Console.Write("{0}:{1}", (index + 1).ToString(),fs[index].ToString());
            }
            catch
            {
               Console.Write("error");
            }
            Console.ReadKey();
        }



    }
}
