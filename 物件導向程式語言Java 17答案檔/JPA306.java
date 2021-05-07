import java.util.Scanner;

public class JPA03 {

	public static void main(String args[]) {

		int a[][] = { { 1, 2, 3 }, { 4, 5, 6 } };
		int b[][] = new int[2][3];
		int c[][] = new int[2][3];

		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
		sc.close();

		String[] data = input.split(" ");
		if (data.length < 6) {
			System.out.print("error");
			return;
		}

		int i = 0;
		for (int x = 0; x < 2; x++) {
			for (int y = 0; y < 3; y++)
				try {
					b[x][y] = Integer.parseInt(data[i]);
					i++;
				} catch (Exception e) {
					System.out.print("error");
					return;
				}
		}

		compute(a, b, c);
		print(c);
	}

	public static void compute(int[][] A, int[][] B, int[][] C) {
		for (int b = 0; b < 2; b++) {
			for (int a = 0; a < 3; a++)
				C[b][a] = A[b][a] + B[b][a];
		}
	}

	public static void print(int[][] s) {
		for (int b = 0; b < 2; b++) {
			for (int a = 0; a < 3; a++)
				System.out.printf("%4d", s[b][a]);
			System.out.println("");
		}
	}
}