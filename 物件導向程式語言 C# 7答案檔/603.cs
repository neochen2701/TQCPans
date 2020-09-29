using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace CSA06
{
    class CSA06
    {
        static void Main(string[] args)
        {

            try
            {
                string data = Console.ReadLine();
                string[] str = data.Split(' ');
                if (str.Length != 4) { throw new Exception(); }
                string workType = str[0].ToLower();
                if (workType != "p" && workType != "f") { throw new Exception(); }
                int rate = int.Parse(str[2]);
                if (rate < 0) { throw new Exception(); }
                int hours = int.Parse(str[3]);
                if (hours < 0) { throw new Exception(); }

                if (workType == "p")
                {
                    PartTime pt = new PartTime(str[1], rate, hours); //TODO
                    Console.Write("PartTime {0} {1}", str[1].ToString(), pt.salary());
                }
                if (workType == "f")
                {
                    FullTime ft = new FullTime(str[1], rate, hours); //TODO
                    Console.Write("FullTime {0} {1}", str[1].ToString(), ft.salary());
                }
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }

    }
    abstract class clerk
    {
        public String name = "";
        public int rate = 0;
        public int hours = 0;
        public clerk(String n, int r, int t)
        {
            name = n;
            rate = r;
            hours = t;
        }
        public abstract double salary();
    }

    //TODO  --class PartTime
    class PartTime : clerk
    {
        public PartTime(String name, int rate, int time) : base(name, rate, time)
        {
        }
        public override double salary()
        {
            return this.rate * this.hours;
        }
    }

    //TODO  --class FullTime
    class FullTime : clerk
    {
        public FullTime(String name, int rate, int time) : base(name, rate, time)
        {
        }
        public override double salary()
        {
            return 8 * this.rate
                + (this.hours - 8) * this.rate * 0.9;
        }
    }
}
