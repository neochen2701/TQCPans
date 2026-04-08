input_1 = int(input())
input_2 = int(input())
input_3 = int(input())

if input_1 >= 60 and input_1 < 100:
    print('1')
else:
    print('0')

print(format((input_2 + 1) / 10, '.2f'))

if input_1 >= input_3:
    print(input_1)
else:
    print(input_3)