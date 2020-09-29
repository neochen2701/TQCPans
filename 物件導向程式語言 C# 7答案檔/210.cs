using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA02
{

    class Div
    {
        int result;
        Div()
        {
            result = 0;
        }
        public void division(int num1, int num2)
        {
            try
            {
                result = num1 / num2;
                Console.Write(result);
            }
            catch (DivideByZeroException)
            {
                Console.Write("error:DivideByZeroException");
            }
        }
        static void Main(string[] args)
        {
            Div d = new Div();
            try
            {
                int n = Convert.ToInt32(Console.ReadLine());
                if (n <= 25)
                {
                    d.division(25, n);
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
