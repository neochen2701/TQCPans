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
                List<string> lst = new List<string>();
                string str = "";
                while (true)
                {
                    str = Console.ReadLine();
                        if (str != "999")
                        {
                            lst.Add(str);
                    }
                    else
                    {
                        break;
                    }
                }
                compute(lst);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }
        // ==================================================
        // Please write your code in the specified Method
        // Do NOT change the method name, type of parameter
        // ==================================================
        static void compute(List<string> lst)
        {
            Console.WriteLine("before:" + String.Join(" ", lst));
            lst.Reverse();
            Console.WriteLine("after:" + String.Join(" ", lst));
        }
  
    }
}
