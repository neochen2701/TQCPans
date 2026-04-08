x1 = eval(input())
y1 = eval(input())
x2 = eval(input())
y2 = eval(input())

dist = ((x2-x1)**2 + (y2-y1)**2)**(0.5)

print("(", x1, ",", y1, ")")
print("(", x2, ",", y2, ")")
print("Distance = %.4f" % dist)
