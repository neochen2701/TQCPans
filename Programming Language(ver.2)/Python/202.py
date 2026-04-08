n = int(input())
if n > 60:
    n += 10
else:
    n += 5

if n >= 0 and n <= 100:
    print(n)
else:
    print('error')