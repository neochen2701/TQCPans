#include <stdio.h>

#define ROW 4
#define COL 4

int getNum(int board[ROW][COL], int row, int col, int *result)
{
    if (board[row][col] != 0)
    {
        return 0;
    }

    int data[6] = {1, 2, 3, 4, 5, 6};

    for (int i = 0; i < COL; ++i)
    {
        if (board[row][i] != 0)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (data[j] == board[row][i])
                {
                    data[j] = 0;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < ROW; ++i)
    {
        if (board[i][col] != 0)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (data[j] == board[i][col])
                {
                    data[j] = 0;
                    break;
                }
            }
        }
    }

    int start_row = 2 * (row / 2);
    int start_col = 2 * (col / 2);

    for (int i = start_row; i < start_row + 2; ++i)
    {
        for (int j = start_col; j < start_col + 2; ++j)
        {
            if (board[i][j] != 0)
            {
                for (int k = 0; k < 4; ++k)
                {
                    if (data[k] == board[i][j])
                    {
                        data[k] = 0;
                        break;
                    }
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (data[i] != 0)
        {
            *result = data[i];
            ++count;
        }
    }

    return (count == 1) ? 1 : 0;
}

int modifyBoard(int board[ROW][COL])
{
    int change = 0;
    for (int row = 0; row < ROW; ++row)
    {
        for (int col = 0; col < COL; ++col)
        {
            int num;
            if (getNum(board, row, col, &num) == 1)
            {
                board[row][col] = num;
                change = 1;
            }
        }
    }
    return change;
}

void printBoard(int board[ROW][COL])
{
    for (int row = 0; row < ROW; ++row)
    {
        for (int col = 0; col < COL; ++col)
        {
            printf("%d", board[row][col]);
            if (col < COL - 1) printf(" ");
        }
        printf("\n");
    }
}

void getData(int board[ROW][COL])
{
    for (int row = 0; row < ROW; ++row)
    {
        for (int col = 0; col < COL; ++col)
        {
            scanf("%d", &board[row][col]);
        }
    }
}

void processOnce()
{
    int board[ROW][COL];
    getData(board);
    while (modifyBoard(board) == 1)
        ;
    printBoard(board);
}

int main()
{
    processOnce();
    return 0;
}
