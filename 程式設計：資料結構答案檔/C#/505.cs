using System;

public class Program
{
    static readonly int SIZE = 4;

    public static void Main(string[] args)
    {
        int[,] board = new int[SIZE, SIZE];
        for (int row = 0; row < SIZE; row++)
        {
            string[] inputs = Console.ReadLine().Split();
            for (int col = 0; col < SIZE; col++)
            {
                board[row, col] = int.Parse(inputs[col]);
            }
        }

        SolveSudoku(board);
        PrintBoard(board);
    }

    private static bool SolveSudoku(int[,] board)
    {
        bool filled;
        do
        {
            filled = FillBoard(board);
        } while (filled);
        return true;
    }

    private static bool FillBoard(int[,] board)
    {
        bool actionTaken = false;
        for (int row = 0; row < SIZE; row++)
        {
            for (int col = 0; col < SIZE; col++)
            {
                if (board[row, col] == 0)
                {
                    bool[] possible = FindPossibleNumbers(board, row, col);
                    if (UpdateCell(board, possible, row, col))
                    {
                        actionTaken = true;
                    }
                }
            }
        }
        return actionTaken;
    }

    private static bool[] FindPossibleNumbers(int[,] board, int row, int col)
    {
        bool[] possible = new bool[SIZE + 1];
        for (int i = 1; i <= SIZE; i++)
        {
            possible[i] = true;
        }

        for (int i = 0; i < SIZE; i++)
        {
            possible[board[row, i]] = false;
            possible[board[i, col]] = false;
            int subRow = 2 * (row / 2) + i / 2;
            int subCol = 2 * (col / 2) + i % 2;
            possible[board[subRow, subCol]] = false;
        }

        return possible;
    }

    private static bool UpdateCell(int[,] board, bool[] possible, int row, int col)
    {
        int count = 0, num = 0;
        for (int i = 1; i <= SIZE; i++)
        {
            if (possible[i])
            {
                count++;
                num = i;
            }
        }
        if (count == 1)
        {
            board[row, col] = num;
            return true;
        }
        return false;
    }

    private static void PrintBoard(int[,] board)
    {
        for (int row = 0; row < SIZE; row++)
        {
            for (int col = 0; col < SIZE; col++)
            {
                if (col < SIZE - 1)
                    Console.Write($"{board[row, col]} ");
                else
                    Console.Write(board[row, col]);
            }
            Console.WriteLine();
        }
    }
}
