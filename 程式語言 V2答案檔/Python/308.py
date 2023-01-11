fib = [0, 1]
def compute(x):
    global fib
    for i in range(x):
        fib.append(fib[-1] + fib[-2])
    return fib[x]

n = int(input())
Fib_n = compute(n)
for i in range(n, 0, -1):
    print('fib(' + str(i) + ')=' + str(fib[i]))