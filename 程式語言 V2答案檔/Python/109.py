n = int(input())

if n < 60:
    print('fail')
elif n <= 100:
    print('pass')
else:
    print('error')

if n <= 100 and n % 2 == 0:
    print('even')
elif n <= 100 and n % 2 != 0:
    print('odd')