using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Collections;

namespace CSA05
{
    class CSA05
    {
        static void Main(string[] args)
        {
            try
            {
                string str = Console.ReadLine();
                if (str=="") { throw new Exception(); }
                int i = 0;
                using (StreamReader sr = new StreamReader(AppDomain.CurrentDomain.BaseDirectory + "/read.txt", Encoding.ASCII))
                {
                    string data = sr.ReadToEnd().Trim();
                    int index = data.IndexOf(str);
                    while (index != -1)
                    {
                        i++;
                        index = data.IndexOf(str, index + 1);
                    }
                }
                Console.Write(i);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }


    }
}
