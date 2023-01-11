size = input().split(' ')
matrix = []
for i in range(int(size[0])):
    row = input().replace(' ', ',')
    matrix.append(row)

for i in range(int(size[0])):
    print(matrix[i])
