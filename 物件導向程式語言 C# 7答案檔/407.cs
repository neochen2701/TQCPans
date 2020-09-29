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
                //TODO
                int seed = int.Parse(Console.ReadLine());
                if (seed < 2000 || 2018 < seed)
                {
                    throw new ArgumentException("seed should be in [2000, 2018]");
                }

                HashSet<string> set = new HashSet<string>();

                // define the day randge: ${seed}/1/1 - ${seed+1}/1/1(excluded)
                DateTime startDay = new DateTime(seed, 1, 1);
                DateTime endDay = new DateTime(seed + 1, 1, 1);
                int totalDays = (endDay - startDay).Days; // consider the leap year

                Random rand = new Random(seed);
                DateTime randomDay;
                TimeSpan offset; // day to ticks
                string randomDate;

                while (set.Count() < 10)
                {
                    offset = new TimeSpan(
                        TimeSpan.TicksPerDay * rand.Next(0, totalDays));
                    randomDay = startDay + offset;

                    if (randomDay.DayOfWeek == DayOfWeek.Saturday
                        || randomDay.DayOfWeek == DayOfWeek.Sunday)
                    {
                        continue;
                    }
                    randomDate = randomDay.Month + "/" + randomDay.Day;
                    set.Add(randomDate);
                }

                Console.Write("{0}:{1}",
                    seed, String.Join(" ", set));//TODO
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }
    }
}
