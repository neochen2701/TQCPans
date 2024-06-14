using System;
using System.Collections.Generic;

public class Program
{
    public class Rectangle
    {
        public int Area, Top, Left, Bottom, Right;

        public Rectangle(int area, int top, int left, int bottom, int right)
        {
            Area = area;
            Top = top;
            Left = left;
            Bottom = bottom;
            Right = right;
        }
    }

    public static Rectangle LargestRectangleArea(List<int> heights, int row)
    {
        int n = heights.Count;
        List<int> left = new List<int>(new int[n]);
        List<int> right = new List<int>(new int[n]);
        for (int i = 0; i < n; i++) right[i] = n;
        Stack<int> stk = new Stack<int>();
        Rectangle maxRect = new Rectangle(0, row, 0, row, 0);

        for (int i = 0; i < n; ++i)
        {
            while (stk.Count > 0 && heights[stk.Peek()] >= heights[i])
            {
                right[stk.Peek()] = i;
                stk.Pop();
            }
            left[i] = stk.Count == 0 ? 0 : stk.Peek() + 1;
            stk.Push(i);
        }

        for (int i = 0; i < n; ++i)
        {
            int area = heights[i] * (right[i] - left[i]);
            if (area > maxRect.Area)
            {
                maxRect = new Rectangle(area, row - heights[i] + 1, left[i], row, right[i] - 1);
            }
        }

        return maxRect;
    }

    public static Rectangle FindLargestRectangleArea(List<List<int>> matrix)
    {
        int n = matrix.Count;
        if (n == 0) return new Rectangle(0, 0, 0, 0, 0);
        int m = matrix[0].Count;
        if (m == 0) return new Rectangle(0, 0, 0, 0, 0);

        List<int> heights = new List<int>(new int[m]);
        Rectangle maxRect = new Rectangle(0, 0, 0, 0, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                heights[j] = matrix[i][j] == 1 ? heights[j] + 1 : 0;
            }
            Rectangle rect = LargestRectangleArea(heights, i);
            if (rect.Area > maxRect.Area)
            {
                maxRect = rect;
            }
        }

        return maxRect;
    }

    public static void Main(string[] args)
    {
        string[] firstLine = Console.ReadLine().Split(' ');
        int n = int.Parse(firstLine[0]);
        int m = int.Parse(firstLine[1]);

        List<List<int>> matrix = new List<List<int>>();
        for (int i = 0; i < n; i++)
        {
            List<int> row = new List<int>();
            string[] line = Console.ReadLine().Split(' ');
            for (int j = 0; j < m; j++)
            {
                row.Add(int.Parse(line[j]));
            }
            matrix.Add(row);
        }

        Rectangle maxRect = FindLargestRectangleArea(matrix);
        Console.WriteLine(maxRect.Area);
        Console.WriteLine($"({maxRect.Top}, {maxRect.Left})");
        Console.WriteLine($"({maxRect.Bottom}, {maxRect.Right})");
    }
}