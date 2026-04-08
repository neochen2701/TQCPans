using System;

class TQC407
{
    static void Main(string[] args)
    {
        string[] lines = System.IO.File.ReadAllLines(@"read.txt");
        for (int i = 0; i < lines.Length; i++)
        {
            lines[i] = lines[i].Replace("*", "");
        }
        System.IO.File.WriteAllLines(@"write.txt", lines);
    }
}