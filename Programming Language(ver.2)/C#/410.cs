using System;
using System.Collections.Generic;
using System.IO;

public class TQC410
{
    public static void Main(string[] args)
    {
        int n;
        n = int.Parse(Console.ReadLine());
        List<string> fileContent = GetNRowsFromFile("read.txt", n);
        List<string> upperSentences = ConvertWordsPrefixToUpper(fileContent);
        PrintContents(upperSentences);
        WriteContentToFile("write.txt", upperSentences);
    }

    public static List<string> ConvertWordsPrefixToUpper(List<string> strList) {
        List<string> result = new List<string>();
        foreach (string str in strList) {
            string[] words = str.Split(' ');
            for (int i = 0; i < words.Length; i++) {
                if (words[i] != "") {
                    words[i] = words[i].Substring(0, 1).ToUpper() + words[i].Substring(1);
                }
            }
            result.Add(String.Join(" ", words));
        }
        return result;
    }

    public static void PrintContents(List<string> contents) {
        foreach (string content in contents) {
            Console.WriteLine(content);
        }
    }

    public static List<string> GetNRowsFromFile(string filePath, int n) {
        List<string> content = new List<string>();
        using (StreamReader reader = new StreamReader(filePath)) {
            string line = "";
            while (((line = reader.ReadLine()) != null) && (n-- > 0)) {
                content.Add(line);
            }
        }
        return content;
    }

    public static void WriteContentToFile(string filePath, List<string> contents) {
        using (StreamWriter writer = new StreamWriter(filePath)) {
            for (int i = 0; i < contents.Count; i++) {
                string line = contents[i];
                if (i == contents.Count - 1)
                    writer.Write(line);
                else
                    writer.WriteLine(line);
            }
        }
    }
}