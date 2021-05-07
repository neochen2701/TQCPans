import java.util.Scanner;

public class JPA02 {

	public static void main(String[] args) {

		try {
			Scanner sc = new Scanner(System.in);
			int num1, num2;
			num1 = sc.nextInt();
			num2 = sc.nextInt();
			if (num1 > 100 || num2 > 100 || num1 < 0 || num2 < 0) {
				System.out.print("error");
				return;
			}
			sc.close();

			int temp;
			while (num1 % num2 != 0) {
				temp = num2;
				num2 = num1 % num2;
				num1 = temp;
			}

			System.out.print(num2);
		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}
