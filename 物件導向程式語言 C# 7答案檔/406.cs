using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA04
{
    class CSA04
    {
        static void Main(string[] args)
        {
            try
            {
                string str = "";
                //TODO
                int seed = int.Parse(Console.ReadLine());
                if (seed < 1 || 100 < seed)
                {
                    throw new ArgumentException("seed should be in [1, 100]");
                }

                Random rand = new Random(seed);
                HashSet<int> set = new HashSet<int>();
                while (set.Count < 10)
                {
                    set.Add(rand.Next(1, 101)); // in [1, 100]
                }
                str = String.Join(" ", set);

                Console.Write(str.Trim());
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }
    }
}
