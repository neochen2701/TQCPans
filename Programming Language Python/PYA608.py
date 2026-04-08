size = 3
mat = []

for i in range(size):
    mat.append([])
    for j in range(size):
        mat[i].append(eval(input()))

max_num = min_num = mat[0][0]
max_index = min_index = [0, 0]

for i in range(size):
    for j in range(size):
        if mat[i][j] > max_num:
            max_num = mat[i][j]
            max_index = [i, j]
        elif mat[i][j] < min_num:
            min_num = mat[i][j]
            min_index = [i, j]

print("Index of the largest number %d is: (%d, %d)" 
      % (max_num, max_index[0], max_index[1]))
print("Index of the smallest number %d is: (%d, %d)" 
      % (min_num, min_index[0], min_index[1]))