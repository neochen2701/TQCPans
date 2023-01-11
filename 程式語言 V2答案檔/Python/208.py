n = int(input())
isprime = 1
for i in range(2, n):
    isprime = 1
    for j in range(2, int(i/2) + 1):
        if i % j == 0:
            # print(str(i) + ' ' + str(j))
            isprime = 0
            break
    if isprime:
        print(str(i) + ' ', end = '')
print()