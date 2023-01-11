size = input().split(' ')
height, width = int(size[0]), int(size[1])
matrix = []

# input
for i in range(height):
    input_row = input().split(' ')
    row_list = []
    for j in range(len(input_row)):
        row_list.append(input_row[j])
    matrix.append(row_list)

# generate output
for i in range(height):
    output_str = ''
    for j in range(width):
        if matrix[i][j] == '1':
            if (i == 0) or (j == 0) or (i == height - 1) or (j == width - 1):
                output_str += '*'
            else:
                if matrix[i-1][j] == '0' or matrix[i+1][j] == '0' or matrix[i][j-1] == '0' or matrix[i][j+1] == '0':
                    output_str += '*'
                else:
                    output_str += ' '
        else:
            output_str += ' '
    print(output_str)
