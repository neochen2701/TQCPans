from decimal import Decimal, ROUND_HALF_UP

def compute(float_list):
    return min(float_list)

float_list = []
for i in range(3):
    n = int(input())
    float_list.append(n)

for i in range(3):
    n = int(input())
    float_list[i] /= n
f = compute(float_list)
f_round = Decimal(str(f)).quantize(Decimal('0.000'), rounding = ROUND_HALF_UP)
print(f_round)