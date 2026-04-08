with open('read.txt') as f:
    contents = f.readlines()
    contents = [contents[i].rstrip('\n') for i in range(len(contents))]

for i in range(3):
    n = input()
    print(n * int(n) + contents[i][int(n):])