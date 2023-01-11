f = open('read.txt','r')
line = f.read()
f.close()

wf = open('write.txt','w')
for i in line:
    if i == 'y':
        wf.write('a')
    elif i == 'z':
        wf.write('b')
    else:
        wf.write(chr(ord(i)+2))


wf.close()