from decimal import Decimal, ROUND_HALF_UP

num = []
add = 0
formula = ''

for i in range(3):
    n = input()
    num.append(n)
    add += int(n)

formula = str(num[0] + '+' + num[1] + '+' + num[2] + '=' +  str(add))
print(formula)
mean = Decimal(str(add / 3)).quantize(Decimal('0.00'), rounding = ROUND_HALF_UP)
print("%.2f" % mean)