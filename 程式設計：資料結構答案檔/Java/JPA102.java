import java.util.Scanner;

public class JPA102 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();

        int[][] matrix = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        System.out.println("Original:");
        for (int i = 0; i < m; i++) {
            System.out.print("[");
            for (int j = 0; j < n; j++) {
                System.out.print(matrix[i][j]);
                if (j < n - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println("]");
        }

        System.out.println("Transpose:");
        for (int i = 0; i < n; i++) {
            System.out.print("[");
            for (int j = 0; j < m; j++) {
                System.out.print(matrix[j][i]);
                if (j < m - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println("]");
        }
    }
}
