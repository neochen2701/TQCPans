def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def generate_prime_matrix(matrix):
    prime_matrix = [[0] * len(matrix) for _ in range(len(matrix))]
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            if is_prime(matrix[i][j]):
                prime_matrix[i][j] = matrix[i][j]
    return prime_matrix

def perform_operations(matrix, operations):
    for op in operations:
        op_type, index, value = op[0], op[1], op[2]
        if op_type == 'A':
            for i in range(len(matrix)):
                matrix[i][index] += value
            for j in range(len(matrix[index])):
                matrix[index][j] += value
        elif op_type == 'R':
            matrix[index] = [elem - value for elem in matrix[index]]
        elif op_type == 'S':
            for i in range(len(matrix)):
                matrix[i][index] *= value
    return matrix

if __name__ == '__main__':
    n = int(input())
    matrix = [list(map(int, input().split())) for _ in range(n)]
    m = int(input())
    operations = [input().split() for _ in range(m)]
    operations = [(op[0], int(op[1]), int(op[2])) for op in operations]

    result_matrix = perform_operations(matrix, operations)

    prime_matrix = generate_prime_matrix(result_matrix)

    for row in result_matrix:
        print(' '.join(map(str, row)))

    for row in prime_matrix:
        print(' '.join(map(str, row)))
