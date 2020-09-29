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
                int r = Convert.ToInt32(Console.ReadLine());
                if (r < 1 || r > 5) { throw new Exception(); }
                account jack = new account("jack",r);
                using (StreamReader sr = new StreamReader(AppDomain.CurrentDomain.BaseDirectory + "/read.txt", Encoding.UTF8))
                {
                    while (!sr.EndOfStream)
                    {
                        string line = sr.ReadLine();
                        string[] money = line.Split(',');
                        if (money[2].ToString() == "d")
                        {
                            jack.deposit(Convert.ToInt32(money[1].ToString()));
                        }else if (money[2].ToString() == "w")
                        {
                            jack.withdraw(Convert.ToInt32(money[1].ToString()));
                        }

                    }
                }
                jack.addInterest();
                 Console.Write("{1}", r,jack.getBalance());
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
        String name="";
        int rate=0;
        double balance=0;

        public account(String name, int rate)
        {
            this.name = name;
            this.rate = rate;
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
