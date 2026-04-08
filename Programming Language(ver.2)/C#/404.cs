using System;
using System.Collections.Generic;

public class TQC404
{
    public static void Main(string[] args)
    {
        string inputStr;
        Dictionary<char, int> characterCountMap = new Dictionary<char, int>();

        inputStr = Console.ReadLine();

        for (int i = 0; i < inputStr.Length; i++) {
            if (characterCountMap.ContainsKey(inputStr[i])) {
                characterCountMap[inputStr[i]]++;
            }
            else {
                characterCountMap.Add(inputStr[i], 1);
            }
        }

        char maxChar = '_';
        int maxCount = 0;
        foreach (KeyValuePair<char, int> element in characterCountMap) {
            if (element.Value > maxCount) {
                maxChar = element.Key;
                maxCount = element.Value;
            }
        }

        Console.WriteLine(maxChar);
        Console.WriteLine(maxCount);
    }
}