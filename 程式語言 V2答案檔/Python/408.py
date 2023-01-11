str1, str2 = input(), input()
if len(str1) <= 3 or len(str1) > 20 or len(str2) <= 3 or len(str2) > 20:
    print('error')
else:
    print(len(str1))
    print(len(str2))
    print(str2[::-1] + str1[::-1])