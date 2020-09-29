using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace CSA01
{
    class CSA01
    {
        const string dreams = "There are moments in life when you miss someone so much that " +
            "you just want to pick them from your dreams and hug them for real! Dream what " +
            "you want to dream;go where you want to go;be what you want to be,because you have " +
            "only one life and one chance to do all the things you want to do";
        static void Main(string[] args)
        {
            string word = Console.ReadLine();
            int pos1 = dreams.IndexOf(word);
            int pos2 = dreams.LastIndexOf(word);
            int length;
            string words;

            if (pos1 >= 0)
            {
                if (pos1 < pos2)
                {
                    length = (pos2 + word.Length) - pos1;
                }
                else
                {
                    pos2 = -1;
                    length = dreams.Length - pos1;
                }
                words = dreams.Substring(pos1, length);
            }
            else
            {
                words = String.Empty;
            }
            print(pos1 + 1, pos2 + 1, words);
        }
        static void print(int pos1, int pos2, string words)
        {//pos1=>first，pos2=>last，words=>capture
            Console.WriteLine("first:" + pos1);
            Console.WriteLine("last:" + pos2);
            Console.Write("capture:" + words);
            Console.ReadKey();
        }
    }
}
