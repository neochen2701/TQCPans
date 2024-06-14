using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    class SubarrayResult
    {
        public int Start { get; set; }
        public int End { get; set; }
    }

    static void Main()
    {
        var arr = new List<int>();
        var input = Console.ReadLine().Split(' ');
        foreach (var item in input)
        {
            arr.Add(int.Parse(item));
        }

        if (arr.Count == 0)
        {
            Console.WriteLine("0\n0\n0");
            return;
        }

        var result = MaxSubarraySum(arr);
        int maxSum = 0;
        for (int i = result.Start; i <= result.End; i++)
        {
            maxSum += arr[i];
        }

        Console.WriteLine(maxSum);
        Console.WriteLine(result.Start);
        Console.WriteLine(result.End);
    }

    static SubarrayResult MaxSubarraySum(List<int> arr)
    {
        return MaxSubarraySumHelper(arr, 0, arr.Count - 1);
    }

    static SubarrayResult MaxSubarraySumHelper(List<int> arr, int low, int high)
    {
        if (low == high)
        {
            return new SubarrayResult { Start = low, End = high };
        }

        int mid = (low + high) / 2;
        var left = MaxSubarraySumHelper(arr, low, mid);
        var right = MaxSubarraySumHelper(arr, mid + 1, high);
        var crossing = MaxCrossingSum(arr, low, mid, high);

        int leftSum = arr.GetRange(left.Start, left.End - left.Start + 1).Sum();
        int rightSum = arr.GetRange(right.Start, right.End - right.Start + 1).Sum();
        int crossingSum = arr.GetRange(crossing.Start, crossing.End - crossing.Start + 1).Sum();

        if (leftSum >= rightSum && leftSum >= crossingSum)
        {
            return left;
        }
        else if (rightSum >= leftSum && rightSum >= crossingSum)
        {
            return right;
        }
        else
        {
            return crossing;
        }
    }

    static SubarrayResult MaxCrossingSum(List<int> arr, int low, int mid, int high)
    {
        int leftSum = int.MinValue, rightSum = int.MinValue;
        int sum = 0;
        int maxLeft = mid, maxRight = mid;

        for (int i = mid; i >= low; i--)
        {
            sum += arr[i];
            if (sum > leftSum)
            {
                leftSum = sum;
                maxLeft = i;
            }
        }

        sum = 0;
        for (int i = mid + 1; i <= high; i++)
        {
            sum += arr[i];
            if (sum > rightSum)
            {
                rightSum = sum;
                maxRight = i;
            }
        }

        return new SubarrayResult { Start = maxLeft, End = maxRight };
    }
}
