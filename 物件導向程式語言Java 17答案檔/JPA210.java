import java.util.Scanner;

public class JPA02 {

	public static void main(String[] args) {

		try {
			Scanner sc = new Scanner(System.in);
			int num1 = 25;
			int num2 = sc.nextInt();
			sc.close();

			if (num2 > 25) {
				System.out.print("error");
				System.exit(0);
			}

			int ans = num1 / num2;
			System.out.print(ans);

		} catch (ArithmeticException e) {
			System.out.print("error:DivideByZeroException");
			System.exit(1);

		} catch (Exception e) {
			System.out.print("error");
			System.exit(1);
		}
	}
}