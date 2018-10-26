def compute(mat, num_row, num_col):
    for i in range(num_row):
        for j in range(num_col):
            print("%d" % mat[i][j], end=' ')
        print()


ROWs = COLs = 2
mat1 = []
mat2 = []

print("Enter matrix 1:")
for i in range(ROWs):
    mat1.append([])
    for j in range(COLs):
        print("[%d, %d]: " % (i + 1, j + 1), end='')
        mat1[i].append(eval(input()))

print("Enter matrix 2:")
for i in range(ROWs):
    mat2.append([])
    for j in range(COLs):
        print("[%d, %d]: " % (i + 1, j + 1), end='')
        mat2[i].append(eval(input()))

print("Matrix 1:")
compute(mat1, ROWs, COLs)
print("Matrix 2:")
compute(mat2, ROWs, COLs)

print("Sum of 2 matrices:")
for i in range(ROWs):
    for j in range(COLs):
        print("%d" % (mat1[i][j] + mat2[i][j]), end=' ')
    print()
