using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Threading;
namespace CSA06
{
    class CSA06
    {
        static void Main(string[] args)
        {
            try
            {
                string str = Console.ReadLine();

                int hh = Convert.ToInt32(str.ToString());
                if (hh < 1)
                {
                    throw new ArgumentException();
                }
                List<Manager> mgers = new List<Manager>();
                List<Worker> wors = new List<Worker>();

                //TODO
                string[] records = System.IO.File.ReadAllLines("read.txt");
                string[] tokens;
                string name;
                char level;
                int hours;
                staff staff;

                foreach (string record in records)
                {
                    tokens = record.Split(',');
                    name = tokens[0];
                    level = tokens[1][0];
                    hours = int.Parse(tokens[3]);
                    if (hours < hh)
                    {
                        continue;
                    }

                    if (level == 'm')
                    {
                        staff = chkManager(mgers, tokens);
                    }
                    else
                    {
                        staff = chkWorker(wors, tokens);
                    }
                    staff.takeLeave(hours);
                }

                int ml = 0, wl = 0;
                foreach (Manager m in mgers)
                {
                    ml += m.leavehours;
                }
                foreach (Worker w in wors)
                {
                    wl += w.leavehours;
                }
                Console.Write("Manager{0}hr/Worker{1}hr", ml, wl);

            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }
        private static Manager chkManager(List<Manager> ms, string[] data)
        {
            foreach (Manager m in ms)
            {
                if (m.name == data[0].ToString())
                {
                    return m;
                }
            }
            Manager newm = new Manager(data[0].ToString());
            ms.Add(newm);
            return newm;
        }
        private static Worker chkWorker(List<Worker> ss, string[] data)
        {
            foreach (Worker s in ss)
            {
                if (s.name == data[0].ToString())
                {
                    return s;
                }
            }
            Worker news = new Worker(data[0].ToString());
            ss.Add(news);
            return news;
        }
    }



    public abstract class staff : ILeave
    {
        public string name = "";
        public bool isleader = false;
        public int leavehours = 0;

        public abstract void takeLeave(int leavehours);
    }

    public class Manager : staff
    {
        public Manager(string n)
        {
            this.name = n;
            this.isleader = true;
        }

        // TODO  --leavehours
        public override void takeLeave(int leavehours)
        {
            this.leavehours += leavehours;
        }
    }
    // TODO --interface ILeave
    interface ILeave
    {
        void takeLeave(int leavehours);
    }

    // TODO --class Worker
    public class Worker : staff
    {
        public Worker(string name)
        {
            this.name = name;
            this.isleader = false;
        }

        public override void takeLeave(int leavehours)
        {
            this.leavehours += leavehours;
        }
    }
}
