n = eval(input())
sum_series = 0

for i in range(2, n+1):
    sum_series += 1 / ((i-1)**0.5 + i**0.5)
print("%.4f" % sum_series)