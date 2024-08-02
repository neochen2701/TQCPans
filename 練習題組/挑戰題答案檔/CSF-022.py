def main():
    n, m = map(int, input().split())

    check_board = []
    for i in range(n):
        check_board.append(input().split())

    for i in range(n):
        for j in range(m):
            if check_board[i][j] == '.':
                # count bomb
                bomb = 0
                for k in range(-1, 2):
                    if i+k >= n or i+k < 0:
                        continue 

                    for l in range(-1, 2):
                        if j+l >= m or j+l < 0:
                            continue

                        if check_board[i+k][j+l] == '*':
                            bomb += 1

                check_board[i][j] = bomb

    for i in range(n):
        print(' '.join(map(str, check_board[i])))



if __name__ == '__main__':
    main()