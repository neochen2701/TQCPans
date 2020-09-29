using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA03
{
    class CSA03
    {
        static int[,] a = { { 1, 2, 3 }, { 4, 5, 6 } };
        static int[,] b = new int[2, 3];
        static void Main(string[] args)
        {
            try
            {
                string[] str = Console.ReadLine().Split(' ');
                if (str.Length != 6) { throw new Exception(); }
                for (int i = 0; i <= str.Length - 1; i++)
                {
                    if (Convert.ToInt32(str[i]) < 1 || Convert.ToInt32(str[i]) > 100)
                    {
                        throw new Exception();
                    }
                    else
                    {
                        b[i <= 2 ? 0 : 1, i > 2 ? i - 3 : i] = Convert.ToInt32(str[i]);
                    }
                }
                int[,] c = compute();
                print(c);

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
        static int[,] compute()
        {
            try
            {
                int[,] c = new int[2, 3];
                for (int i = 0; i <= 1; i++)
                {
                    for (int j = 0; j <= 2; j++)
                    {
                        c[i, j] = a[i, j] + b[i, j];
                    }
                }
                return c;
            }
            catch
            {
                return null;
            }
        }

        static void print(int[,] c)
        {
            for (int i = 0; i <= 1; i++)
            {
                for (int j = 0; j <= 2; j++)
                {
                    Console.Write(c[i, j].ToString().PadLeft(4));
                }
                Console.WriteLine();
            }
        }
    }
}
