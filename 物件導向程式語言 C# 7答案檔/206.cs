using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA02
{
    class CSA02
    {
        const string dreams = "There are moments in life when you miss someone so much that " +
    "you just want to pick them from your dreams and hug them for real! Dream what " +
    "you want to dream;go where you want to go;be what you want to be,because you have " +
    "only one life and one chance to do all the things you want to do";
        static void Main(string[] args)
        {
            try
            {
                string x1 = Console.ReadLine();
                int times = 0;
                int pos = dreams.IndexOf(x1);
                while (pos > -1)
                {
                    times += 1;
                    pos = dreams.IndexOf(x1,pos + 1);
                }
 
                Console.Write(times.ToString());
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }

    }
}
