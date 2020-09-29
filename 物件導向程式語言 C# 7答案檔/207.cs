using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA02
{
    class CSA02
    {

        static void Main(string[] args)
        {
            try
            {
                string str = Console.ReadLine();
                for(int i = 0; i <= str.Length - 1; i++)
                {
                    Char x = Convert.ToChar(str.Substring(i, 1));
                    Console.WriteLine("ASCII code for '" + x + "' is " + Convert.ToByte(x).ToString());
                }
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }

    }
}
