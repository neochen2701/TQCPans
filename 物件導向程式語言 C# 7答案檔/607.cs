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
            account acc;
            try
            {
                string sin = Console.ReadLine();
                string[] sArray = sin.Split(',');

                //TODO


                string name = sArray[0];                
            
                int year = Convert.ToInt32(sArray[1]);
                
                if (year == 0)
                    acc = new account(name);
                else if (1 <= year && year <= 3)
                    acc = new account(name, year);
                else
                    throw new Exception();

                using (StreamReader sr = new StreamReader(AppDomain.CurrentDomain.BaseDirectory + "/read.txt", Encoding.UTF8))
                {
                    while (!sr.EndOfStream)
                    {
                        string line = sr.ReadLine();
                        string[] data = line.Split(',');
                        if (name.Equals(data[0]))
                        {
                            int amount = Convert.ToInt32(data[1]);
                            string act = data[2];
                            if (act.Equals("d"))
                                acc.deposit(amount);
                            else
                                acc.withdraw(amount);
                        }
                    }
                }
                acc.addInterest();
                if (!acc.isCD)
                {
                    Console.Write("{0},F,{1}%,{2}", acc.name, acc.rate, acc.getBalance());
                }
                else
                {
                    Console.Write("{0},T,{1}%,{2}", acc.name, acc.rate, acc.getBalance());
                }

                
             }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }
    }
    class account
    {
        public string name="";
        public int rate=1;
        double balance=0;
        public bool isCD = false;
        public int duration = 0;
        public account(String name)
        {
            this.name = name;
        }
        public account(String name,int d)
        {            
            this.name = name;
            this.duration = d;
            this.isCD = true;
            switch (duration)
            {
                case 1: rate = 2; break;
                case 2: rate = 3; break;
                case 3: rate = 5; break;
            }
        }

        public void setRate(int rate)
        {
            this.rate = rate;
        }

        public void deposit(int n)
        {
            balance += n;
        }

        public void withdraw(int n)
        {
            balance -= n;
        }
        public double getBalance()
        {
            return balance ;
        }
        public void addInterest()
        {
            balance = balance * Convert.ToDouble(1 + (rate/100.0));
        }
    }

}
