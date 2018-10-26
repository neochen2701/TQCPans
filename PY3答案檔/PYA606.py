def compute(lst):
    for i in range(len(lst)):
        for j in range(len(lst[i])):
            print("%4d" % lst[i][j], end='')
        print()


row = eval(input())
column = eval(input())
lst = []

for i in range(row):
    lst.append([])
    for j in range(column):
        lst[i].append(j - i)

compute(lst)
