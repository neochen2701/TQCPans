import math

PI = math.pi

radius = float(input())

print("Radius = %.2f" % radius)
print("Perimeter = %.2f" % (2*radius*PI))
print("Area = %.2f" % (pow(radius, 2)*PI))
