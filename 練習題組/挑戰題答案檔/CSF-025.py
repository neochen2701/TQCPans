def maxSubarraySum(item):
    currentSum = item[0]
    maxSum = item[0]

    for i in range(1,len(item)):
        currentSum = max(item[i], currentSum + item[i])
        maxSum = max(maxSum,currentSum)
    return maxSum


if __name__ == "__main__":
    number = int(input())
    item = [int(i) for i in input().split()]
    result = maxSubarraySum(item)
    print(result)

