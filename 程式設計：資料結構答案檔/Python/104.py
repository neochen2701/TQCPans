import sys

def find_lower_area(map, x, y, w, h):
    if map[x][y] > 0:
        return 0
    if map[x][y] == -2:
        return 0
    if map[x][y] == -1:
        return 0
    map[x][y] = -1
    return (1 + find_lower_area(map, x-1, y, w, h) + find_lower_area(map, x+1, y, w, h)
              + find_lower_area(map, x, y-1, w, h) + find_lower_area(map, x, y+1, w, h))

def show_map(map, w, h):
    for i in range(1, w+1):
        for j in range(1, h+1):
            print(map[i][j], end=" ")
        print()
    print()

m, n = (int(x) for x in input().split())

map = [[-2 for _ in range(n+2)] for _ in range(m+2)] 

for i in range(1, m+1):
    row = [int(x) for x in input().split()]
    for j in range(1, n+1):
        map[i][j] = row[j-1]

maxSize = 0
for i in range(1, m+1):
    for j in range(1, n+1):
        size = find_lower_area(map, i, j, m, n)
        if size > maxSize:
            maxSize = size

print(maxSize)
