import math
from decimal import Decimal, ROUND_HALF_UP

a = int(input())
b = int(input())
s = math.sqrt(a + b)
res = Decimal(str(s)).quantize(Decimal('0.00'), rounding = ROUND_HALF_UP)
print('result=' + str(res))
