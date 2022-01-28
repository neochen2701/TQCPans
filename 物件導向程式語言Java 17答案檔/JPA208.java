import java.util.Scanner;

public class JPA02 {

	public static void main(String args[]) {

		try {
			Scanner sc = new Scanner(System.in);
			int num = sc.nextInt();
			sc.close();

			if (num > 9 || num < 0) {
				System.out.print("error");
				return;
			}

			for (int i = 1; i <= num; i++) {
				for (int j = i; j > 0; j--) {
					System.out.printf("%d*%d=%02d  ", i, j, i * j);
				}
				System.out.println();
			}
		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}
