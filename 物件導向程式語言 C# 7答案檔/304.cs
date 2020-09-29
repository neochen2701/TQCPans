using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA03
{
    class CSA03
    {
        static int[] scores = new int[] { 100, 100, 95, 95, 92, 91, 90, 100, 88, 88, 87, 87, 90, 91, 85, 80, 81, 82, 82, 89 };
        static void Main(string[] args)
        {
            int remove = 0;
            Int32.TryParse(Console.ReadLine(), out remove);
            List<int> resultList = new List<int>();
            foreach(int data in scores)
            {
                if (data != remove)
                {
                    resultList.Add(data);
                }
            }
            
            Console.Write(resultList.Average().ToString("f2"));
                    
            
            Console.ReadKey();
        }



    }
}
