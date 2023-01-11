using System;

public class TQC610
{
    public static void Main(string[] args)
    {
        int[,] matrixA = InputMatrix();
        int[,] matrixB = InputMatrix();
        if (ValidateMatrixCanMultiple(matrixA, matrixB))
            PrintMatrix(MatrixMultiplication(matrixA, matrixB));
        else
            Console.Write("error");
    }

    public static bool ValidateMatrixCanMultiple(int[,] matrixA, int[,] matrixB) {
        int n = matrixA.GetLength(1);
        int m = matrixB.GetLength(0);
        return n == m;
    }

    public static int[,] MatrixMultiplication(int[,] matrixA, int[,] matrixB) {
        int n = matrixA.GetLength(0);
        int m = matrixB.GetLength(1);
        int[,] matrix = new int[n, m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int s = 0;
                for (int k = 0; k < matrixA.GetLength(1); k++) {
                    s += matrixA[i, k] * matrixB[k, j];
                }
                matrix[i, j] = s;
            }
        }

        return matrix;
    }

    public static int[,] InputMatrix() {
        int a = 1, b = 1;
        string[] inp = Console.ReadLine().Split(' ');
        a = Convert.ToInt32(inp[0]);
        b = Convert.ToInt32(inp[1]);
        int[,] matrix =  new int[a, b];
        for (int i = 0; i < a; i++) {
            inp = Console.ReadLine().Split(' ');
            for (int j = 0; j < b; j++) {
                matrix[i, j] = Convert.ToInt32(inp[j]);
            }
        }
        return matrix;
    }

    public static void PrintMatrix(int[,] matrix) {
        for (int i = 0; i < matrix.GetLength(0); i++) {
            for (int j = 0; j < matrix.GetLength(1); j++) {
                Console.Write(matrix[i, j].ToString());
                if (j != matrix.GetLength(1) - 1)
                    Console.Write(" ");
            }
            Console.WriteLine("");
        }
    }
}