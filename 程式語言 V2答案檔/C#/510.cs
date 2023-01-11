using System;
using System.Collections.Generic;

public class TQC510
{
    public static void Main(string[] args)
    {
        List<string> inputs = new List<string>();
        int n, m;
        string input;
        input = Console.ReadLine();
        n = Convert.ToInt32(input.Split(' ')[0]);
        m = Convert.ToInt32(input.Split(' ')[1]);
        for (int i = 0; i < n; i++) {
            input = Console.ReadLine();
            inputs.Add(String.Join("", input.Split(' ')));
        }
        PrintMatrix(GetNewMatrix(inputs, n, m));
    }

    public static List<string> GetNewMatrix(List<string> inputs, int n, int m) {
        List<string> matrix = new List<string>();
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < m; j++) {
                if (inputs[i][j] == '1') {
                    if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                        row += "*";
                    else if (inputs[i][j - 1] == '0' || inputs[i - 1][j] == '0' || inputs[i + 1][j] == '0' || inputs[i][j + 1] == '0')
                        row += "*";
                    else
                        row += " ";
                }
                else {
                    row += " ";
                }
            }
            matrix.Add(row);
        }
        return matrix;
    }

    public static void PrintMatrix(List<string> triangle) {
        foreach (string line in triangle) {
            Console.WriteLine(line);
        }
    }
}