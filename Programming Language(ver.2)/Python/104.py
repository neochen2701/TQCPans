from decimal import Decimal, ROUND_HALF_UP

a = float(input())
b = float(input())
total = Decimal(str(a+b)).quantize(Decimal('0.00'), rounding = ROUND_HALF_UP)
print('total=' + str(total))
