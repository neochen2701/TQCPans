using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA02
{
    class CSA02
    {
        static void Main(string[] args)
        {
            double x1, x2;
            double.TryParse(Console.ReadLine(), out x1);
            double.TryParse(Console.ReadLine(), out x2);
            if(x1 < x2)
            {
                Console.Write(x1 + "<" + x2);
            }else if( x1 > x2){
                Console.Write(x1 + ">" + x2);
            }else{
                Console.Write(x1 + "=" + x2);
            }
            
            Console.ReadKey();
        }



    }
}
