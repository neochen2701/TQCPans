import math
from decimal import Decimal, ROUND_HALF_UP

x1 = int(input())
y1 = int(input())
x2 = int(input())
y2 = int(input())

distance_tmp = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
distance = Decimal(str(distance_tmp)).quantize(Decimal('0.00'), rounding = ROUND_HALF_UP)
print(distance)