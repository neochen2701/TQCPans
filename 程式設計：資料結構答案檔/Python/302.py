def bubble_sort(arr):
    print(" ".join(map(str, arr)))

    for i in range(n):
        swapped = False
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        if not swapped:
            break
        print(" ".join(map(str, arr)))

n = int(input())

input_numbers = list(map(int, input().split()))

bubble_sort(input_numbers)