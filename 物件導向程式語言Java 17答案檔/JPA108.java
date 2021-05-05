import java.util.Scanner;

public class JPA01 {

	public static void main(String[] args) {

		try {
			Scanner sc = new Scanner(System.in);
			double num = sc.nextDouble();
			sc.close();
			System.out.printf("%.4f", f(num));

		} catch (Exception e) {
			System.out.print("error");
		}
	}

	public static double f(double num) {
		return (2 * (Math.pow(num, 3)) + 3 * num - 1);
	}
}