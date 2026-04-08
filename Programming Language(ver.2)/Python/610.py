# read matrix 1
size1 = [int(x) for x in input().split(' ')]
matrix1 = []
for i in range(size1[0]):
    row = [int(x) for x in input().split(' ')]
    matrix1.append(row)

# read matrix 2
size2 = [int(x) for x in input().split(' ')]
matrix2 = []
for i in range(size2[0]):
    row = [int(x) for x in input().split(' ')]
    matrix2.append(row)

# check size
if size1[1] != size2[0]:
    print('error')
    exit()

# count
output_matrix = []
for i in range(size1[0]):
    row = []
    for j in range(size2[1]):
        cnt = 0
        for k in range(size1[1]):
            cnt += matrix1[i][k] * matrix2[k][j]
        row.append(cnt)
    output_matrix.append(row)

# print
for i in range(len(output_matrix)):
    for j in range(len(output_matrix[0])):
        if j != len(output_matrix[0]) - 1:
            print(output_matrix[i][j], end = ' ')
        else:
            print(output_matrix[i][j])
