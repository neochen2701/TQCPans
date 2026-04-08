def compute(n):
    isprime = 1
    for i in range(2, int(n/2) + 1):
        if n % i == 0:
            isprime = 0
    return isprime

n = int(input())
if compute(n):
    print(str(n) + ' is a prime number')
else:
    print(str(n) + ' is not a prime number')