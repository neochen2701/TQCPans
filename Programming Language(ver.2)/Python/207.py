n = int(input())
isprime = 1
for i in range(2, int(n/2) + 1):
    if n % i == 0:
        print(str(n) + ' is not a prime number')
        isprime = 0
        break
if isprime:
    print(str(n) + ' is a prime number')
