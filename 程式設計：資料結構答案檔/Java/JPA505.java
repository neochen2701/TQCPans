import java.util.Scanner;

public class JPA505 {
    static final int SIZE = 4;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[][] board = new int[SIZE][SIZE];

        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                board[row][col] = scanner.nextInt();
            }
        }

        solveSudoku(board);
        printBoard(board);
    }

    private static boolean solveSudoku(int[][] board) {
        boolean filled = true;
        do {
            filled = fillBoard(board);
        } while (filled);
        return true;
    }

    private static boolean fillBoard(int[][] board) {
        boolean actionTaken = false;
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (board[row][col] == 0) {
                    boolean[] possible = findPossibleNumbers(board, row, col);
                    if (updateCell(board, possible, row, col)) {
                        actionTaken = true;
                    }
                }
            }
        }
        return actionTaken;
    }

    private static boolean[] findPossibleNumbers(int[][] board, int row, int col) {
        boolean[] possible = new boolean[SIZE + 1];
        for (int i = 1; i <= SIZE; i++) {
            possible[i] = true;
        }

        for (int i = 0; i < SIZE; i++) {
            possible[board[row][i]] = false;
            possible[board[i][col]] = false;
            possible[board[2 * (row / 2) + i / 2][2 * (col / 2) + i % 2]] = false;
        }

        return possible;
    }

    private static boolean updateCell(int[][] board, boolean[] possible, int row, int col) {
        int count = 0, num = 0;
        for (int i = 1; i <= SIZE; i++) {
            if (possible[i]) {
                count++;
                num = i;
            }
        }
        if (count == 1) {
            board[row][col] = num;
            return true;
        }
        return false;
    }

    private static void printBoard(int[][] board) {
        for (int[] row : board) {
            for (int c = 0; c < row.length; c++) {
                System.out.print(row[c]);
                if (c < row.length - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}
