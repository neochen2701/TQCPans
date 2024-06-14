using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        int m = int.Parse(Console.ReadLine());
        List<string> fabrics = new List<string>();

        for (int i = 0; i < m; i++)
        {
            fabrics.Add(Console.ReadLine());
        }

        fabrics.Sort();

        int ans = 0;
        foreach (var s1 in fabrics)
        {
            int len = s1.Length;
            for (int i = 1; i <= len / 2; i++)
            {
                if (s1.Substring(0, i) == s1.Substring(len - i, i))
                {
                    string subStr = s1.Substring(i, len - 2 * i);
                    if (fabrics.BinarySearch(subStr) >= 0)
                    {
                        ans++;
                    }
                }
            }
        }

        Console.WriteLine(ans);
    }
}
