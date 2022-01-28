import java.util.Scanner;

public class JPA02 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int num1 = 0, num2 = 0;
		try {
			num1 = sc.nextInt();
			num2 = sc.nextInt();
			sc.close();
			if (num1 > 100 || num2 > 100 || num1 <= 0 || num2 <= 0) {
				System.out.print("error");
				return;
			}
		} catch (Exception e) {
			System.out.print("error");
			return;
		}
		int i;
		int j;
		for (i = num1; i <= num2; i++) {
			int n = (int) Math.sqrt(i);
			for (j = 2; j <= n; j++) {
				if (i % j == 0) {
					break;
				}
			}
			if (j == n + 1) {
				if (i != 1)
					System.out.println(i);
			}
		}
	}
}
