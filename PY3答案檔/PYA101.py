num1 = int(input())
num2 = int(input())
num3 = int(input())
num4 = int(input())

#向右靠齊
print("|%5d %5d|" % (num1, num2))
print("|%5d %5d|" % (num3, num4))

#向左靠齊
print("|%-5d %-5d|" % (num1, num2))
print("|%-5d %-5d|" % (num3, num4))