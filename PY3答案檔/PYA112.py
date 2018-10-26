num1 = eval(input())
num2 = eval(input())
num3 = eval(input())
num4 = eval(input())

# 靠右對齊
print("|%8.3f %8.3f|" % (num1, num2))
print("|%8.3f %8.3f|" % (num3, num4))

# 靠左對齊
print("|%-8.3f %-8.3f|" % (num1, num2))
print("|%-8.3f %-8.3f|" % (num3, num4))