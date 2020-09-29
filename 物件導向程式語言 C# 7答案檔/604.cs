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
                string[] tokens = Console.ReadLine().Split();
                if (tokens.Length != 2)
                {
                    throw new ArgumentException();
                }
                int pRate = int.Parse(tokens[0]);
                int fRate = int.Parse(tokens[1]);
                double salaryTotal = calculateTotalSalary(pRate, fRate);
                Console.Write("PartTime:{0},FullTime:{1},Salary:{2}",
                    pRate, fRate, salaryTotal);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }

        static double calculateTotalSalary(int pRate, int fRate)
        {
            string[] lines = System.IO.File.ReadAllLines("read.txt");
            string[] tokens;
            char workType;
            string name;
            int hours;
            clerk clerk = null;
            double salaryTotal = 0;

            foreach (string line in lines)
            {
                tokens = line.Split(',');
                workType = tokens[0][0];
                name = tokens[1];
                hours = int.Parse(tokens[2]);
                switch (workType)
                {
                    case 'm':
                        clerk = new FullTime(name, fRate, hours);
                        clerk.isManager = true;
                        break;
                    case 'f':
                        clerk = new FullTime(name, fRate, hours);
                        clerk.isManager = false;
                        break;
                    case 'p':
                        clerk = new PartTime(name, pRate, hours);
                        break;
                }
                salaryTotal += clerk.salary();
                //Console.WriteLine("{0} => {1}", line, clerk.salary());
            }
            return salaryTotal;
        }
    }

    abstract class clerk
    {
        public String name = "";
        public int rate = 0;
        public int hours = 0;
        public bool isManager = false;

        public clerk(String n, int r, int t)
        {
            name = n;
            rate = r;
            hours = t;
        }
        public abstract double salary();
    }
    class PartTime : clerk
    {
        public PartTime(String n, int r, int t) : base(n, r, t)
        {

        }

        public override double salary()
        {
            return hours * rate;
        }

    }
    class FullTime : clerk
    {
        public FullTime(String n, int r, int t) : base(n, r, t)
        {

        }

        public override double salary()
        {
            double salary = 8 * rate + ((hours - 8) * rate * 0.9);
            if (this.isManager)
            {
                salary *= 1.2;
            }
            return salary;
        }

    }
}
