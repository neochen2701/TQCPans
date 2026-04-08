import math
from decimal import Decimal, ROUND_HALF_UP

input_float = []
for i in range(6):
    input_float.append(float(input()))
ans = abs(input_float[0]) * math.floor(input_float[1]) + (input_float[2] ** input_float[3]) * math.sqrt(input_float[4]) + math.log(input_float[5], 10)
# print(ans)
ans_round = Decimal(str(ans)).quantize(Decimal('.00'), rounding = ROUND_HALF_UP)
print(ans_round)