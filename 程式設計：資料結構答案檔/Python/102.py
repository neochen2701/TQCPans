m = int(input())
n = int(input())

matrix = []
for i in range(m):
    row = []
    for j in range(n):
        row.append(int(input()))
    matrix.append(row)

print("Original:")
for row in matrix:
    print("[" + " ".join([str(value) for value in row]) + "]")

transpose_matrix = []
for i in range(n):
    row = []
    for j in range(m):
        row.append(matrix[j][i])
    transpose_matrix.append(row)

print("Transpose:")
for row in transpose_matrix:
    print("[" + " ".join([str(value) for value in row]) + "]")
