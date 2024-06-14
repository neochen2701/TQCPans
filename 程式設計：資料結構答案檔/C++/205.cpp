#include <iostream>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

struct Rectangle
{
    int area;
    int top;
    int left;
    int bottom;
    int right;
};

Rectangle largestRectangleArea(const vector<int> &heights, int row)
{
    int n = heights.size();
    vector<int> left(n), right(n, n);
    stack<int> stk;
    Rectangle maxRect{0, row, 0, row, 0};

    for (int i = 0; i < n; ++i)
    {
        while (!stk.empty() && heights[stk.top()] >= heights[i])
        {
            right[stk.top()] = i;
            stk.pop();
        }
        left[i] = stk.empty() ? 0 : stk.top() + 1;
        stk.push(i);
    }

    for (int i = 0; i < n; ++i)
    {
        int area = heights[i] * (right[i] - left[i]);
        if (area > maxRect.area)
        {
            maxRect.area = area;
            maxRect.top = row - heights[i] + 1;
            maxRect.left = left[i];
            maxRect.bottom = row;
            maxRect.right = right[i] - 1;
        }
    }

    return maxRect;
}

Rectangle findLargestRectangleArea(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    if (n == 0)
        return {0, 0, 0, 0, 0};
    int m = matrix[0].size();
    if (m == 0)
        return {0, 0, 0, 0, 0};

    vector<int> heights(m, 0);
    Rectangle maxRect{0, 0, 0, 0, 0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            heights[j] = (matrix[i][j] == 1) ? heights[j] + 1 : 0;
        }
        Rectangle rect = largestRectangleArea(heights, i);
        if (rect.area > maxRect.area)
        {
            maxRect = rect;
        }
    }

    return maxRect;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Rectangle maxRect = findLargestRectangleArea(matrix);
    cout << maxRect.area << endl;
    cout << "(" << maxRect.top << ", " << maxRect.left << ")" << endl;
    cout << "(" << maxRect.bottom << ", " << maxRect.right << ")" << endl;

    return 0;
}
