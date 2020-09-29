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
        static string title = "The Little Prince";
        static string content = "To me, you are still nothing more than a little boy who is just like a hundred thousand other little boys. And I have no need of you. And you, on your part, have no need of me. To you, I am nothing more than a fox like a hundred thousand other foxes. But if you tame me, then we shall need each other. To me, you will be unique in all the world. To you, I shall be unique in all the world.";
        static void Main(string[] args)
        {
            try
            {
                string row = Console.ReadLine();
                int lines = 0;
                //TODO
                string fileName = "write.txt";
                string[] paragraphInArray = content.Split(
                    new char[] { '.' },
                    System.StringSplitOptions.RemoveEmptyEntries);
                List<string> paragraphInList = new List<string>();
                paragraphInList.Add(title);

                // check the argument
                if (row == String.Empty)
                {
                    lines = int.MaxValue;
                }
                else
                {
                    lines = int.Parse(row);
                    if (lines < 1)
                    {
                        throw new ArgumentException();
                    }
                }

                lines = Math.Min(lines, paragraphInArray.Length);
                for (int i = 0; i < lines; i++)
                {
                    paragraphInList.Add(paragraphInArray[i] + ".");
                }
                System.IO.File.WriteAllLines(
                    fileName, paragraphInList.ToArray());

            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }

    }
}

