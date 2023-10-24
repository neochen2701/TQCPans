def compute(arr):
    W = arr[0]
    H = arr[1]
    total_stars = 0
    for i in range(H):
        for j in range(W):
            print('*', end='')
            total_stars += 1
        print()
    return total_stars

input_array = []
input_array.append(int(input()))
input_array.append(int(input()))
total_stars = compute(input_array)
print(total_stars)