using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace CSA05
{
    class CSA05
    {
        static void Main(string[] args)
        {
            try
            {
                int row =Convert.ToInt32(Console.ReadLine());

                if (row < 1 || row > 10) { throw new Exception(); }
                StreamReader sr = new StreamReader(AppDomain.CurrentDomain.BaseDirectory + "/read.txt", Encoding.Default);
                string data = "";
                for(int i = 1; i <= row; i++)
                {
                    data = sr.ReadLine();
                }
                Console.Write("{0}:{1}" , row , data);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }



    }
}
