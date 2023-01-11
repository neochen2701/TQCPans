n = int(input())
a = [input().split(' ') for i in range(n)]
PI = 3.14159
# r = (int(a[0][2]),int(a[1][2]),int(a[2][2]))
r = [int(a[i][2]) for i in range(n)]
cnt = 0
for i in range(n):
    cnt += int(a[i][2]) ** 2
print("Sum = {:.2f}".format(cnt * PI))
for idx in range(3):
    if int(a[idx][2]) == max(r):
        print("x: "+str(a[idx][0]) + ", y: "+str(a[idx][1])+"\nradius: "+str(a[idx][2]))
        break