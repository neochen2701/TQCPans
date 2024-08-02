def sumCount(nums1, nums2, nums3, price):
    numDict = {}
    for i in nums1:
        for j in nums2:
            if i + j not in numDict:
                numDict[i + j] = 1
            else:
                numDict[i + j] += 1
    for i in nums2:
        for j in nums3:
            if i + j not in numDict:
                numDict[i + j] = 1
            else:
                numDict[i + j] += 1
    for i in nums1:
        for j in nums3:
            if i + j not in numDict:
                numDict[i + j] = 1
            else:
                numDict[i + j] += 1

    total = 0
    for key, value in numDict.items():
        if key <= price:
            total += value

    return total

def main():
    money = int(input())
    low_count, *low_prices = map(int, input().split())
    medium_count, *medium_prices = map(int, input().split())
    high_count, *high_prices = map(int, input().split())
    print(sumCount(low_prices, medium_prices, high_prices, money))

if __name__ == '__main__':
    main()
