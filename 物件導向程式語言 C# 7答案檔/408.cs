using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Globalization;

namespace CSA04
{
    class CSA04
    {
        static void Main(string[] args)
        {
            try
            {
                //TODO
                int days, hours, minutes;
                ParseTime(Console.ReadLine(), out hours, out minutes);
                days = hours / 8;
                hours = hours % 8;
                Console.Write("{0}d:{1}h:{2}m", days, hours, minutes); //TODO
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }

        static void ParseTime(string s, out int hours, out int minutes)
        {
            //DateTime dt = DateTime.ParseExact(
            //    Console.ReadLine(), "HH:mm", CultureInfo.InvariantCulture);
            string[] tokens = s.Split(':');
            if (tokens.Length != 2)
            {
                throw new ArgumentException();
            }

            // check the rule: \d{1,2}:\d{1,2}
            if (tokens[0].Length > 2 || tokens[1].Length > 2)
            {
                throw new ArgumentException();
            }

            hours = int.Parse(tokens[0]);
            minutes = int.Parse(tokens[1]);
            if (hours < 0 || minutes < 0 || minutes > 59)
            {
                throw new ArgumentException();
            }
        }
    }
}