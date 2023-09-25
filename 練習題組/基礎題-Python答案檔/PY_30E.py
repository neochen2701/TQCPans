a = int(input())
b = int(input())
min_value = a if a < b else b
result = 1

for i in range(min_value):
    if a % (i+1) == 0 and b % (i+1) == 0:
        result = (i+1)

print(result)