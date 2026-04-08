using System;
using System.Collections.Generic;
using System.IO;

public class TQC706
{
    public static void Main(string[] args)
    {
        List<int> fileContent = GetContentFromFile("read.txt");
        InputNumberToList(fileContent, 4);
        fileContent.Sort();
        PrintList(fileContent);
        WriteContentToFile("write.txt", fileContent);
    }

    public static void InputNumberToList(List<int> list, int n) {
        for (int i = 0; i < n; i++) {
            list.Add(int.Parse(Console.ReadLine()));
        }
    }

    public static void PrintList(List<int> list) {
        for (int i = 0; i < list.Count; i++) {
            Console.WriteLine(list[i]);
        }
    }

    public static List<int> GetContentFromFile(string filePath) {
        List<int> content = new List<int>();
        using (StreamReader reader = new StreamReader(filePath)) {
            string line = "";
            while ((line = reader.ReadLine()) != null) {
                content.Add(Convert.ToInt32(line));
            }
        }
        return content;
    }

    public static void WriteContentToFile(string filePath, List<int> contents) {
        using (StreamWriter writer = new StreamWriter(filePath)) {
            for (int i = 0; i < contents.Count; i++) {
                int line = contents[i];
                if (i == contents.Count - 1)
                    writer.Write(line);
                else
                    writer.WriteLine(line);
            }
        }
    }
}