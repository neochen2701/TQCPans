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
            for (int i = 0; i <= 4; i++)
            {
                Int32.TryParse(Console.ReadLine(), out numbers[i]);
            }
            compute(numbers);
        }
        // ==================================================
        // Please write your code in the specified Method
        // Do NOT change the method name, type of parameter
        // ==================================================
        static void compute(int[] numbers)
        {
            int tmp;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (numbers[j] > numbers[j + 1])
                    {
                        tmp = numbers[j];
                        numbers[j] = numbers[j + 1];
                        numbers[j + 1] = tmp;
                    }
                }
            }
            Console.Write(string.Join(" ", numbers));
            Console.ReadKey();
        }

    }
}
