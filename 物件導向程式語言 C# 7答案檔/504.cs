using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace CSA05
{
    class CSA05
    {
        static string[] new_student = { "Sam", "1981/10/1", "A234567890" };
        static void Main(string[] args)
        {
            try
            {
                //TODO
                string line = String.Join(",", new_student);
                string[] scoreList = Console.ReadLine().Split(new char[] { ' ' });
                int score;

                if (scoreList.Length != 3)
                {
                    throw new ArgumentException();
                }
                for (int i = 0; i < scoreList.Length; i++)
                {
                    score = int.Parse(scoreList[i]);
                    if (score < 0 || 100 < score)
                    {
                        throw new ArgumentException();
                    }
                }
                line += "," + String.Join(",", scoreList);

                using (StreamWriter writer = new StreamWriter("write.txt", true))
                {
                    writer.WriteLine(line);
                }
                Console.Write(line);
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }


    }
}
