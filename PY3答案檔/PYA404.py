number = eval(input())

if number == 0:
    print(number)
else:
    while number != 0:
        print(number % 10, end='')
        number //= 10
