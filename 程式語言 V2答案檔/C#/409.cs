using System;
using System.Collections.Generic;
using System.IO;

public class TQC409
{
    public static void Main(string[] args)
    {
        List<string> fileContent = GetContentFromFile("read.txt");
        WriteContentToFile("write.txt", EncryptStringList(fileContent));
    }

    public static List<string> EncryptStringList(List<string> strList) {
        List<string> result = new List<string>();
        foreach (string str in strList) {
            string encryption = "";
            for (int i = 0; i < str.Length; i++) {
                if (str[i] >= 'y') {
                    encryption += Convert.ToChar(str[i] - 26 + 2);
                }
                else {
                    encryption += Convert.ToChar(str[i] + 2);
                }
            }
            result.Add(encryption);
        }
        return result;
    }

    public static List<string> GetContentFromFile(string filePath) {
        List<string> content = new List<string>();
        using (StreamReader reader = new StreamReader(filePath)) {
            string line = "";
            while ((line = reader.ReadLine()) != null) {
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