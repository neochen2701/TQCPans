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
        static string[] data = {"Life is difficult, life is unfair, life is challenging and sometimes painful. And life is so very good."
        , "There are frustrations, tragedies, disappointments, setbacks, heartbreaks, and absurdities. The simple joy of being outweighs them all."
        , "Life is good, because within its realm, anything is possible. Life is good, because no matter how far you fall, there is always a way to climb back up again."
        , "You can complain, fret and worry about all the problems in your life, but you'll be wasting your time. Or, you can choose to focus on why and how life is so good, and on what you can do to take that goodness and make it even better."
        , "Not only is life good, it's uniquely good for you in your very own way. The possibilities for expressing your purpose are limited only by your imagination."
        , "Remind yourself often of the great and wonderful value that you already, always have. Life is good, and in this moment that's bursting with possibilities, life is yours."};
        static void Main(string[] args)
        {
            try
            {
                //TODO
                int lineNumber = int.Parse(Console.ReadLine());
                if (lineNumber < 1 || 6 < lineNumber)
                {
                    throw new ArgumentException();
                }

                //    string fileName = "write.txt";
                //    using (FileStream stream = new FileStream(
                //        fileName, FileMode.Create, FileAccess.Write))
                //    {
                //        using (StreamWriter writer = new StreamWriter(
                //            stream, Encoding.UTF8))
                //        {
                //            for (int i = 0; i < lineNumber; i++)
                //            {
                //                writer.WriteLine(data[i]);
                //            }
                //        }
                //    }
                //}


                using (StreamWriter writer = new StreamWriter("write.txt", true))
                {
                    for (int i = 0; i < lineNumber; i++)
                    {
                        writer.WriteLine(data[i]);
                    }
                }
            }

            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }


    }
}