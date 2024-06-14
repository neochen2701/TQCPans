def is_valid(board, row, col, num):
    if num in board[row]:
        return False
    if num in [board[i][col] for i in range(4)]:
        return False
    start_row, start_col = 2 * (row // 2), 2 * (col // 2)
    for i in range(start_row, start_row + 2):
        for j in range(start_col, start_col + 2):
            if board[i][j] == num:
                return False    
    return True

def print_board(board):
    for row in board:
        print(' '.join(map(str, row)))


def needOne(data:list)->int:
    for i in range(1,len(data)+1):
        if data.count(i)==0:
            return i
        
def getOneZeroIndex_eachRow(board: list)->int:
    if board.count(0)!=1: return -1
    for i in range(len(board)):
        if board[i]==0:
            return i

def getOneZeroIndex_Column(board:list)->list:    
    change = 0
    for col in range(len(board)):
        column = [board[i][col] for i in range(len(board))]
        index =getOneZeroIndex_eachRow(column)
        if index !=-1:
            num = needOne(column)
            board[index][col]=num
            change = change + 1
    return change        

def getOneZeroIndex_Row(board: list)->int:
    change = 0
    for row in board:
        index =getOneZeroIndex_eachRow(row)
        if index !=-1:
            num = needOne(row)
            row[index] = num
            change = change + 1
    return change

def getOneZeroIndex_Block(board: list)->int:
    change = 0
    for i in range(len(board)):
        row, col = 2*(i//2), 2*(i%2)
        block = [board[x+row][y+col] for x in range(2) for y in range(2)]
        index =getOneZeroIndex_eachRow(block)
        if index !=-1:
            num = needOne(block)
            board[row+index//2][col+index%2]=num
            change = change + 1
    return change

def check(board):
    change = 0
    while change<8:    
        change += getOneZeroIndex_Row(board)
        change += getOneZeroIndex_Column(board)
        change += getOneZeroIndex_Block(board)
    print_board(board)
    
board = [[int(i) for i in input().split()] for j in range(4)]

check(board)