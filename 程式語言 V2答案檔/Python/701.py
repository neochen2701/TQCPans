import math
from decimal import Decimal, ROUND_HALF_UP

len_list = []
for i in range(3):
    len_list.append(float(input()))

s = sum(len_list) / 2
area = math.sqrt(s * (s - len_list[0]) * (s - len_list[1]) * (s - len_list[2]))
area_round = Decimal(str(area)).quantize(Decimal('.00'), rounding = ROUND_HALF_UP)
print(area_round)