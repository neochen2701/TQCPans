count_1 = 0
count_2 = 0
count_3 = 0
count_4 = 0
count_5 = 0
count_6 = 0
error_count = 0

for i in range(10):
    n = int(input())
    if n == 1:
        count_1 += 1
    elif n == 2:
        count_2 += 1
    elif n == 3:
        count_3 += 1
    elif n == 4:
        count_4 += 1
    elif n == 5:
        count_5 += 1
    elif n == 6:
        count_6 += 1
    else:
        error_count += 1

print('number1:' + str(count_1))
print('number2:' + str(count_2))
print('number3:' + str(count_3))
print('number4:' + str(count_4))
print('number5:' + str(count_5))
print('number6:' + str(count_6))
print('error:' + str(error_count))