l = []
for i in range(4):
    l.append(int(input()))
with open('read.txt','r') as f:
    for i in f:
        l.append(int(i))
l.sort()
with open('write.txt','w') as f:
    for i in l:
        print(i)
        f.write(str(i)+'\n')