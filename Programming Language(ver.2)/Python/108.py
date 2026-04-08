from decimal import Decimal, ROUND_HALF_UP

pi = 3.1415
diameter = int(input())
radius = diameter/2
radius_round = Decimal(str(radius)).quantize(Decimal('0.00'), rounding = ROUND_HALF_UP)
area = Decimal(str((radius ** 2) * pi)).quantize(Decimal('0.0000'), rounding = ROUND_HALF_UP)

print('{0: <10}'.format(diameter))
print('{0: <10}'.format(radius_round))
print('{0: <10}'.format(area))
