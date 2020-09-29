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
                string data =Console.ReadLine();
                if (data == "") { throw new Exception(); }
                string[] str = data.Split(' ');
                if (str.Length != 4) { throw new Exception(); }
                car newcar = new car();
                newcar.cc = Convert.ToInt32(str[0]);
                newcar.seats = Convert.ToInt32(str[1]);
                newcar.color = Convert.ToInt32(str[2]);
                newcar.doors = Convert.ToInt32(str[3]);
                bool isok = Enum.IsDefined(typeof(CarColor), newcar.color);
                if (!isok)
                {
                    throw new Exception();
                }
                CarColor colors;
                Enum.TryParse<CarColor>(newcar.color.ToString(), true, out colors);
                Console.Write("{0}cc{1}{2}{3}", newcar.cc, newcar.seats, colors.ToString(), newcar.doors);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }

    }
    public enum CarColor:int
    {
        RED = 1,
        BLUE = 2,
        WHITE = 3
    }
    class car
    {
        private int _cc = 0;
        public int cc
        {
            get
            {
                return _cc;
            }
            set
            {
                _cc = value;
            }

        }
        private int _seats =0;
        public int seats
        {
            get
            {
                return _seats;
            }
            set
            {
                _seats = value;
            }

        }
        private int _color = 0;
        public int color
        {
            get
            {
                return _color;
            }
            set
            {
                _color = value;
            }
        }

        private int _doors = 0;
        public int doors
        {
            get
            {
                return _doors;
            }
            set
            {
                _doors = value;
            }
        }
    }


}
