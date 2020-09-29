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
                string data = Console.ReadLine();
                string[] score = data.Split(' ');
                if (score.Length != 2) { throw new Exception(); }
                ArrayList res = new ArrayList();
                int i = 0;
                using (StreamReader sr = new StreamReader(AppDomain.CurrentDomain.BaseDirectory + "/read.txt", Encoding.UTF8))
                {
                    while (!sr.EndOfStream)
                    {
                        string line = sr.ReadLine();
                        string[] student = line.Split(',');
                        int ss = Convert.ToInt32(student[3]) + Convert.ToInt32(student[4]) + Convert.ToInt32(student[5]);

                        switch (score[0])
                        {
                            case ">":
                                if (ss > Convert.ToInt32(score[1]))
                                {
                                    i++; res.Add(student[0].ToString() +" " + ss.ToString());
                                }
                                break;
                            case "<":
                                if (ss < Convert.ToInt32(score[1]))
                                {
                                    i++; res.Add(student[0].ToString() + " " + ss.ToString());
                                }
                                break;
                            case "=":
                                if (ss == Convert.ToInt32(score[1]))
                                {
                                    i++; res.Add(student[0].ToString() + " " + ss.ToString());
                                }
                                break;
                            case "<=":
                                if (ss <= Convert.ToInt32(score[1]))
                                {
                                    i++; res.Add(student[0].ToString() + " " + ss.ToString());
                                }
                                break;
                            case ">=":
                                if (ss >= Convert.ToInt32(score[1]))
                                {
                                    i++; res.Add(student[0].ToString() + " " + ss.ToString());
                                }
                                break;
                        }
                    }
                }
                Console.Write("{0}\n{1}", i,string.Join("\n",res.ToArray()));
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }


    }
}
