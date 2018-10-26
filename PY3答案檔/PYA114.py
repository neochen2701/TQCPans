import math

PI = math.pi

radius = eval(input())

print("Diameter = %.2f" % (2*radius))
print("Perimeter = %.2f" % (2*radius*PI))
print("Area = %.2f" % (pow(radius,2)*PI))