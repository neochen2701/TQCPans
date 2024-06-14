def max_subarray_sum(arr):
    if len(arr) == 0:
        return 0

    def max_crossing_sum(arr, low, mid, high):
        left_sum = float('-inf')
        sum = 0
        max_left = 0
        for i in range(mid, low - 1, -1):
            sum += arr[i]
            if sum > left_sum:
                left_sum = sum
                max_left = i

        right_sum = float('-inf')
        sum = 0
        max_right = 0
        for i in range(mid + 1, high + 1):
            sum += arr[i]
            if sum > right_sum:
                right_sum = sum
                max_right = i

        return max_left, max_right, left_sum + right_sum

    def max_subarray_sum_helper(arr, low, high):
        if low == high:
            return low, high, arr[low]

        mid = (low + high) // 2

        left_low, left_high, left_sum = max_subarray_sum_helper(arr, low, mid)
        right_low, right_high, right_sum = max_subarray_sum_helper(arr, mid + 1, high)
        cross_low, cross_high, cross_sum = max_crossing_sum(arr, low, mid, high)

        if left_sum >= right_sum and left_sum >= cross_sum:
            return left_low, left_high, left_sum
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return right_low, right_high, right_sum
        else:
            return cross_low, cross_high, cross_sum

    low, high, max_sum = max_subarray_sum_helper(arr, 0, len(arr) - 1)
    return low, high, max_sum

arr = [int(i) for i in input().split()]
start, end, max_sum = max_subarray_sum(arr)
print(max_sum)
print(start)
print(end)

