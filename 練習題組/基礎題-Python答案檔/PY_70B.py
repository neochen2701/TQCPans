def compute(numbers, target):
    return target in numbers

a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())

numbers = {b, c, d, e}
result = compute(numbers, a)
print(result)
