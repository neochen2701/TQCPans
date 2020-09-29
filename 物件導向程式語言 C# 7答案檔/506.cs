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
                int row = Convert.ToInt32(Console.ReadLine());
                if (row < 1 || row > 13) { throw new Exception(); }
                StringBuilder new_data = new StringBuilder();
                string del_name = "";
                using (StreamReader sr = new StreamReader(AppDomain.CurrentDomain.BaseDirectory + "/read.txt", Encoding.UTF8))
                {
                    while (!sr.EndOfStream)
                    {
                        string line = sr.ReadLine();
                        string[] student = line.Split(',');
                        if(student[0].ToString() != row.ToString())
                        {
                            new_data.AppendLine(line);
                        }
                        else
                        {
                            del_name = student[1].ToString();
                        }
                    }
                }
                StreamWriter sw = new StreamWriter(AppDomain.CurrentDomain.BaseDirectory + "/write.txt", false, Encoding.UTF8);
                sw.Write(new_data);
                sw.Close();
                Console.Write("Delete:{0} {1}",row,del_name);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }


    }
}
