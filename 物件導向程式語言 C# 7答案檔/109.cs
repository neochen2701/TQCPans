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
        static void Main(string[] args)
        {
            try
            {
                string str = Console.ReadLine();
                if (str.Trim() == "") { throw new Exception(); }

                if (str.Length == 1)
                {
                    str = encrypt(str[0]).ToString();
                }
                else
                {
                    str = encrypt(str[0])
                        + str.Substring(1, str.Length - 2)
                        + encrypt(str[str.Length - 1]);
                }
                Console.Write(str);
            }
            catch
            {
                Console.Write("error");
            }

            Console.ReadKey();
        }

        static char encrypt(char ch)
        {
            if ('0' <= ch && ch <= '8')
            {
                ch++;
            }
            else if (ch == '9')
            {
                ch = '0';
            }
            else if (Char.IsUpper(ch))
            {
                ch = (char)(Char.ToLower(ch) + 1);
            }
            else if (Char.IsLower(ch))
            {
                ch = (char)(Char.ToUpper(ch) + 1);
            }
            else
            {
                throw new Exception("unexpected char: " + ch);
            }
            return ch;
        }

    }
}