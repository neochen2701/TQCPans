a = eval(input())
b = eval(input())
opr = input()
ans = 0

if opr == '+':   ans = a + b
elif opr == '-': ans = a - b
elif opr == '*': ans = a * b
elif opr == '/': ans = a / b
elif opr == '//':ans = a // b
elif opr == '%': ans = a % b

print(ans)