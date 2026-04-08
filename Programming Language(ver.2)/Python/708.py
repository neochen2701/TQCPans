cnt = 0
t = []
for i in range(3):
    a,b = input().split()
    t.append((int(a), int(b)))
for i in range(3):
    if t[i][0] < 12:
        if t[i][0] == 0:
            print('AM '+str(t[i][0]+12)+':'+str(t[i][1]))
        else:
            print('AM '+str(t[i][0])+':'+str(t[i][1]))
        cnt+=1
    else: 
        if t[i][0] == 12:
            print('PM '+str(t[i][0])+':'+str(t[i][1]))
        else:
            print('PM '+str(t[i][0]-12)+':'+str(t[i][1]))
print(cnt)