str1 = input()
str2 = input()
n = int(input())
compare = 0

if n > len(str1):
    print('error')
    exit()

for i in range(n):
    compare += ord(str1[i]) - ord(str2[i])

if compare > 0:
    print(str1 + ' > ' + str2)
elif compare < 0:
    print(str1 + ' < ' + str2)
else:
    print(str1 + ' = ' + str2)