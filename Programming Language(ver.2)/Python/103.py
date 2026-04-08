from decimal import Decimal, ROUND_HALF_UP

num1 = int(input())
num2 = int(input())
num3 = int(input())

add = num1 + num2 + num3
formula = f'{num1}+{num2}+{num3}={add}'
print(formula)

mean = Decimal(str(add / 3)).quantize(Decimal('0.00'), rounding=ROUND_HALF_UP)
print("%.2f" % mean)