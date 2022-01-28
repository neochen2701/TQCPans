import java.util.Scanner;

public class JPA03 {

	public static void main(String args[]) {

		try {
			Scanner sc = new Scanner(System.in);
			int i = sc.nextInt();
			sc.close();

			if (i >= 1 && i <= 20)
				System.out.print(compute(i));
			else {
				System.out.print("error");
				return;
			}
		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}

	public static int compute(int i) {
		if (i == 0)
			return 1;
		else
			return i * compute(i - 1);
	}
}