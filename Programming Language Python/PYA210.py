side1 = eval(input())
side2 = eval(input())
side3 = eval(input())

if side1+side2 > side3 \
   and side2+side3 > side1 \
   and side1+side3 > side2:
    print(side1+side2+side3)
else:
    print("Invalid")