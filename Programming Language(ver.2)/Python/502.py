n = input()
ret = 1
mult = ''
for i in range(len(n)):
    ret *= int(n[i])
    mult += n[i]
    if i != len(n) - 1:
        mult += '*'
print(mult + '=' + str(ret))