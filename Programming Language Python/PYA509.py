def compute(a, b):
    gcd = 1
    k = 1
    if a > 0 and b > 0:
        while k <= a and k <= b:
            if a % k == 0 and b % k == 0:
                gcd = k
            k += 1
        return gcd


x, y = eval(input())
m, n = eval(input())

p = x*n + m*y
q = y*n
gcd = compute(p, q)
print('%d/%d + %d/%d = %d/%d' % (x, y, m, n, p/gcd, q/gcd))
