using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace CSA05
{
    class CSA05
    {
        public struct Record
        {
            public int Num;
            public string Line;
            public Record(int num, string line)
            {
                this.Num = num;
                this.Line = line;
            }
            public override string ToString()
            {
                return String.Format("[{0}] {1}", this.Num, this.Line);
            }
        };
        static void Main(string[] args)
        {
            try
            {
                int row = Convert.ToInt32(Console.ReadLine());
                if (row < 5) { throw new Exception(); }
                //TODO
                StreamReader sr1 = new StreamReader("read.txt");
                string results = getStr(sr1, row);
                System.IO.File.WriteAllText("write.txt", results);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }
        static string getStr(StreamReader sr1, int number)
        {
            sr1.BaseStream.Position = 0;

            //TODO
            string line;
            string[] columns;
            List<Record> dataset = new List<Record>();

            while ((line = sr1.ReadLine()) != null)
            {
                if (line.Trim().Length == 0)
                {
                    continue; // skip the empty line
                }
                columns = line.Split(',');
                Record record = new Record(int.Parse(columns[0]), line);
                dataset.Add(record);
                
            }
            
            dataset.Sort((record1, record2) => {
                return record1.Num - record2.Num;
             });

            StringBuilder results = new StringBuilder();
            int count = Math.Min(number, dataset.Count);
            for (int i = 0; i < count; i++)
            {
                Record r = dataset[i];
                results.Append(r.Line);
                results.Append("\n");
            }
            return results.ToString();
        }


    }
}
