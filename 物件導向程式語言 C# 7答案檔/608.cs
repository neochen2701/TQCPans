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
                int c = Convert.ToInt32(Console.ReadLine());
                if (c <= 0) { throw new Exception(); }
                int total = 0;
                using (StreamReader sr = new StreamReader(AppDomain.CurrentDomain.BaseDirectory + "/read.txt", Encoding.UTF8))
                {
                    while (!sr.EndOfStream)
                    {
                        string line = sr.ReadLine();
                        string[] data = line.Split(',');
                        air a = new air(data[0].ToString(), Convert.ToInt32(data[2].ToString()), Convert.ToDouble(data[1].ToString()));
                        a.setcost(c);
                        a.setfreight();
                        total += a.freight;
                    }
                }
                Console.Write(total);

            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }

               
        public class bag
        {
            public string receiptdate = "";
            public int freight = 0;
            public int unitcost = 0;
            public double weight = 0.0;
        }
        public class air : bag
        {
            public int deliveryhours = 0;
            public air(string rd,int h,double w)
            {
                this.receiptdate = rd;
                this.deliveryhours = h;
                this.weight = w;
            }
            public void setcost(int c)
            {
                this.unitcost = c;
            }
            public void setfreight()
            {
                this.freight = this.unitcost * deliveryhours;
            }
        }
    }
}
