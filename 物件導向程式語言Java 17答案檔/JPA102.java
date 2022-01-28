import java.util.Scanner;

public class JPA01 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n1, n2;
		try {
			n1 = sc.nextInt();
		} catch (Exception ex) {
			n1 = 0;
			sc.next();
		}
		try {
			n2 = sc.nextInt();
		} catch (Exception ex) {
			n2 = 0;
		}
		sc.close();

		if (n1 % 2 == 0 && n2 % 2 == 0) {
			System.out.print(n1 + n2);

		} else {
			System.out.print(0);
			return;
		}
	}
}
