amount = eval(input())
rate = eval(input())
months = eval(input())

total = amount
print('%s \t  %s' % ('Month', 'Amount'))
for i in range(1, months + 1):
    total += total * rate / 1200
    print('%3d \t %.2f' % (i, total))
