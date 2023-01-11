l = [int(input()) for i in range(10)]
a = [0, 0, 0, 0]#4
p = 0
for i in l:
    if a.count(i) == 0:
        a[p] = i
        p = (p+1)%4
    print(str(a[0]) + ' ' + str(a[1]) + ' ' + str(a[2]) + ' ' + str(a[3]) + ' ')