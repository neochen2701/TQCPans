a = int(input())
b = int(input())

small = min(a, b)
large = max(a, b)

for i in range(small, 0, -1):
    if (a % i == 0) and (b % i == 0):
        break
print(i)

for j in range(large, small * large + 1):
    if (j % a == 0) and (j % b == 0):
        break
print(j)