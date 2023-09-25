a = int(input())
b = int(input())

total = a + b

if total < 3:
    print("早上")
elif total < 9:
    print("下午")
else:
    print("晚上")