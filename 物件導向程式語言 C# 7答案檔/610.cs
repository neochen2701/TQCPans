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
                string[] data = Console.ReadLine().Split(' ');
                
                for(int i = 0; i < data.Length; i++) 
                    if (Convert.ToDouble(data[i].ToString()) < 0) { throw new Exception(); }
                

                double cost = 0;
                double total = 0;
                Notebook n;
                if (data.Length == 2) {
                    n = new Notebook();
                    n.profit = Convert.ToDouble(data[1].ToString());
                    cost = n.getCost() * Convert.ToDouble(data[0].ToString());
                    total = n.getPrice() * Convert.ToDouble(data[0].ToString());
                }
                else if (data.Length == 5)
                {
                    n = new Notebook(Convert.ToDouble(data[3].ToString()),Convert.ToInt32(data[2].ToString()), Convert.ToInt32(data[4].ToString())){
                        profit = Convert.ToDouble(data[1].ToString())
                    };
                    cost = n.getCost() * Convert.ToDouble(data[0].ToString());
                    total = n.getPrice() * Convert.ToDouble(data[0].ToString());

                }
                else
                {
                    throw new Exception();
                }
                
                Console.Write("NB:{0},Cost:{1},Total:{2}", data[0].ToString(), cost, total);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }


 
    }
    abstract class part
    {
        public int cost;
        public int getCost()
        {
            return cost;
        }
    }
    class LCD : part
    {
        private int _size = 0;
        public int size
        {
            get
            {
                return _size;
            }
            set
            {
                _size = value;
            }
        }
        public LCD(int s)
        {
            size = s;
            if (s == 10)
            {
                this.cost = 1500;
            }
            else if (s == 15)
            {
                this.cost = 2500;
            }
            else if (s == 17)
            {
                this.cost = 3500;
            }
        }
 
 
 
    }
    class CPU : part
    {
        private double _speed;
        public double speed
        {
            get
            {
                return _speed;
            }
            set
            {
                _speed = value;
            }
        }
        public CPU(double s)
        {
            this._speed = s;
            if (s == 1.66)
            {
                this.cost = 7000;
            }
            else if (s == 2.2)
            {
                this.cost = 8500;
            }
            else if (s == 2.4)
            {
                this.cost = 13000;
            }
        }
    }
    class HD : part
    {
        private int _vol = 0;
        public int vol
        {
            get
            {
                return _vol;
            }
            set
            {
                _vol = value;
            }
        }
        public HD(int v)
        {
            this._vol = v;
            if (v == 256)
            {
                this.cost = 1800;
            }
            else if (v == 512)
            {
                this.cost = 2500;
            }
        }
    }
    class Notebook
    {
        LCD lcd;
        CPU cpu;
        HD hd;
        private double _profit = 0.0;
        public Notebook()
        {
            lcd = new LCD(10);
            cpu = new CPU(1.66);
            hd = new HD(256);
        }
        public Notebook(double c, int l, int h)
        {
            lcd = new LCD(l);
            cpu = new CPU(c);
            hd = new HD(h);
        }
        public double profit
        {
            get
            {
                return _profit;
            }
            set
            {
                _profit = value;
            }
        }
        public double getCost()
        {
            return (lcd.getCost() + cpu.getCost() + hd.getCost());
        }
        public double getPrice()
        {
            return (lcd.getCost() + cpu.getCost() + hd.getCost()) * profit;
        }
    }
}
