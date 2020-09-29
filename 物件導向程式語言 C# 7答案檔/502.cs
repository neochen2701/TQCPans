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
        static string FILE_NAME = "write.txt";
        static void Main(string[] args)
        {
            try
            {
                //TODO
                string line = Console.ReadLine();
                if (string.IsNullOrEmpty(line))
                {
                    throw new ArgumentException();
                }
                System.IO.File.WriteAllText(FILE_NAME, line);
                print();
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }

        static void print()
        {
            // TODO
            string line = System.IO.File.ReadAllText(FILE_NAME);
            Console.Write("write:" + line);//TODO
        }


    }
}
