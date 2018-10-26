import math


def compute(num):
    s_num = math.floor(num ** 0.5)
    for i in range(2, (s_num + 1)):
        if (num % i) == 0:
            return False
    return True


x = int(input())

if x > 1:
    if compute(x):
        print('Prime')
    else:
        print('Not Prime')
else:
    print('Not Prime')
