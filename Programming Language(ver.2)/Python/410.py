f = open('read.txt','r')
line = f.readlines()
f.close()
wf = open('write.txt','w')

n = int(input())
for i in line[:n]:
    i = i.strip()
    i = i.split(' ')
    for idx, word in enumerate(i):
        word = word.capitalize()
        if idx == len(i) - 1:
            print(word)
            wf.write(word + '\n')
        else:
            print(word, end = ' ')
            wf.write(word + ' ')
    # print(i)
        # wf.write(word+'\n')
wf.close()