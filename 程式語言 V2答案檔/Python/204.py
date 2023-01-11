a = int(input())
b = int(input())
compute = input()

if compute == '+':
    print(str(a) + '+' + str(b) + '=' + str(a+b))
elif compute == '-':
    print(str(a) + '-' + str(b) + '=' + str(a-b))
elif compute == '*':
    print(str(a) + '*' + str(b) + '=' + str(a*b))
else:
    print('error')