def compute(number_tuple):
    return number_tuple[0] * number_tuple[1]

a = int(input())
b = int(input())

numbers = (a, b)
result = compute(numbers)
print(f'The result is {result}')