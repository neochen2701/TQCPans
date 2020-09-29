using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA03
{
    class CSA03
    {

        static List<int> scores = new List<int> { 100, 100, 95, 95, 92, 91, 90, 100, 88, 88, 87, 87, 90, 91, 85, 80, 81, 82, 82, 89 };
        static void Main(string[] args)
        {
            try
            {
                int score = Convert.ToInt32(Console.ReadLine());

                List<int> finds = scores.FindAll(delegate (int s) {
                    return s.Equals(score);
                });
                Console.Write(finds.Count.ToString());
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }

  
    }
}
