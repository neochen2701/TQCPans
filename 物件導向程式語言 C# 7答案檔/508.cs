using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Collections;

namespace CSA05
{
    class CSA05
    {
        static void Main(string[] args)
        {
            try
            {
                int p = Convert.ToInt32(Console.ReadLine());
                int persB = 0;
                int persG = 0;
                int boyscore = 0; int girlscore = 0;
                using (StreamReader sr = new StreamReader(AppDomain.CurrentDomain.BaseDirectory + "/read.txt", Encoding.UTF8))
                {
                   while (!sr.EndOfStream)
                   {
                        for (int i = 0; i < p; i++)
                        {
                            string line = sr.ReadLine();
                            string[] student = line.Split(',');


                            if (student[1].Substring(1, 1) == "1")
                            {
                               persB += 1;
                               boyscore += Convert.ToInt32(student[2].ToString()) + Convert.ToInt32(student[3].ToString()) + Convert.ToInt32(student[4].ToString());
                            }
                            if (student[1].Substring(1, 1) == "2")
                            {
                                persG += 1;
                                girlscore += Convert.ToInt32(student[2].ToString()) + Convert.ToInt32(student[3].ToString()) + Convert.ToInt32(student[4].ToString());
                            }
                        }
                        sr.Close();
                        Console.Write("boys:"+((boyscore/3)/ persB).ToString()+",girls:"+((girlscore/3)/ persG).ToString());
                    }
                   
                }
              
            }
            catch
            {
               // Console.Write("error");

            }
            Console.ReadKey();
        }


    }
}
