#include <iostream>
#include <vector>

#define ROW 4
#define COL 4

bool getNum(std::vector<std::vector<int>>& board, int row, int col, int& result) {
    if (board[row][col] != 0) {
        return false;
    }

    int data[4] = {1, 2, 3, 4};

    for (int i = 0; i < COL; ++i) {
        if (board[row][i] != 0) {
            for (int j = 0; j < 4; ++j) {
                if (data[j] == board[row][i]) {
                    data[j] = 0;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < ROW; ++i) {
        if (board[i][col] != 0) {
            for (int j = 0; j < 4; ++j) {
                if (data[j] == board[i][col]) {
                    data[j] = 0;
                    break;
                }
            }
        }
    }

    int start_row = 2 * (row / 2);
    int start_col = 2 * (col / 2);

    for (int i = start_row; i < start_row + 2; ++i) {
        for (int j = start_col; j < start_col + 2; ++j) {
            if (board[i][j] != 0) {
                for (int k = 0; k < 4; ++k) {
                    if (data[k] == board[i][j]) {
                        data[k] = 0;
                        break;
                    }
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 4; ++i) {
        if (data[i] != 0) {
            result = data[i];
            ++count;
        }
    }

    return (count == 1);
}

bool modifyBoard(std::vector<std::vector<int>>& board) {
    bool change = false;
    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            int num;
            if (getNum(board, row, col, num)) {
                board[row][col] = num;
                change = true;
            }
        }
    }
    return change;
}

void printBoard(const std::vector<std::vector<int>>& board) {
    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            std::cout << board[row][col];
            if (col < COL - 1) std::cout << " ";
        }
        std::cout << "\n";
    }
}

void getData(std::vector<std::vector<int>>& board) {
    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            std::cin >> board[row][col];
        }
    }
}

void processOnce() {
    std::vector<std::vector<int>> board(ROW, std::vector<int>(COL));
    getData(board);
    while (modifyBoard(board));
    printBoard(board);
}

int main() {
    processOnce();
    return 0;
}
