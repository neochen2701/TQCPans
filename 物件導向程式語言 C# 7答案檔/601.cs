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
                string[] strArray = Console.ReadLine().Split(':');

                int cc = Convert.ToInt32(strArray[0]);
                int y = Convert.ToInt32(strArray[1]);

                if (cc != 1800 && cc != 2000) { throw new Exception(); }
                Engine e = new Engine(cc,y);

                Console.Write("{0}", e.getCost());
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }



    }
    class UnitCost
    {
        public int cost = 0;
        public int getCost()
        {
            return cost;
        }
    }
    class Engine : UnitCost
    {
        private int cc;
        private int y;

  
        public Engine(int cc, int y) 
        {
            this.y = y;
            this.cc = cc;

            if (cc == 1800)
            {
                cost = 20000;
            }
            else if (cc == 2000)
            {
                cost = 25000;
            }

            if (y > 2 && y < 5)
            {
                cost = (int)(cost * 0.8);
            }
            else if (y >= 5 && y < 10)
            {
                cost = (int)(cost * 0.7);
            }
            else if (y >= 10)
            {
                cost = (int)(cost * 0.6);
            }
        }
    }

}
