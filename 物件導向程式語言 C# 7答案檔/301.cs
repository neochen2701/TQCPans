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
            int[] numbers = new int[5];
            // TODO
            float number;
            for (int i = 0; i < numbers.Length; i++)
            {
                float.TryParse(Console.ReadLine(), out number);
                numbers[i] = (int)number;
            }
            compute(numbers);
        }

        // ==================================================
        // Please write your code in the specified Method
        // Do NOT change the method name, type of parameter
        // ==================================================
        static void compute(int[] numbers)
        {
            int sum = 0; int times = 0;
            //TODO
            for (int i = 0; i < numbers.Length; i++)
            {
                if (numbers[i] > 50)
                {
                    sum += numbers[i];
                    times++;
                }
            }

            Console.WriteLine(sum.ToString());
            if (times > 0)
            {
                Console.WriteLine((sum / times).ToString());
            }
            else
            {
                Console.WriteLine("0");
            }
            Console.ReadKey();
        }


    }
}
