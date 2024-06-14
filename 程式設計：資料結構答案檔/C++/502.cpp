#include <iostream>
#include <vector>
#include <climits>
using namespace std;

pair<int, int> max_crossing_sum(vector<int> &arr, int low, int mid, int high)
{
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    int max_right = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }

    return make_pair(max_left, max_right);
}

pair<int, int> max_subarray_sum_helper(vector<int> &arr, int low, int high)
{
    if (low == high)
    {
        return make_pair(low, high);
    }

    int mid = (low + high) / 2;

    pair<int, int> left = max_subarray_sum_helper(arr, low, mid);
    pair<int, int> right = max_subarray_sum_helper(arr, mid + 1, high);
    pair<int, int> crossing = max_crossing_sum(arr, low, mid, high);

    int left_sum = 0;
    for (int i = left.first; i <= left.second; i++)
    {
        left_sum += arr[i];
    }

    int right_sum = 0;
    for (int i = right.first; i <= right.second; i++)
    {
        right_sum += arr[i];
    }

    int crossing_sum = 0;
    for (int i = crossing.first; i <= crossing.second; i++)
    {
        crossing_sum += arr[i];
    }

    if (left_sum >= right_sum && left_sum >= crossing_sum)
    {
        return left;
    }
    else if (right_sum >= left_sum && right_sum >= crossing_sum)
    {
        return right;
    }
    else
    {
        return crossing;
    }
}

pair<int, int> max_subarray_sum(vector<int> &arr)
{
    if (arr.empty())
    {
        return make_pair(0, 0);
    }

    return max_subarray_sum_helper(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr;
    int input;
    while (cin >> input)
    {
        arr.push_back(input);
        if (cin.peek() == '\n')
            break;
    }

    if (arr.size() == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    pair<int, int> result = max_subarray_sum(arr);
    int max_sum = 0;
    for (int i = result.first; i <= result.second; i++)
    {
        max_sum += arr[i];
    }

    cout << max_sum << endl;
    cout << result.first << endl;
    cout << result.second << endl;

    return 0;
}
