import java.util.Scanner;

public class JPA01 {

	public static void main(String[] args) {

		double input = 0;
		try {
			Scanner sc = new Scanner(System.in);
			input = sc.nextDouble();
			sc.close();
		} catch (Exception e) {

		}
		calCircle(input);
	}

	public static void calCircle(double input) {
		final double pi = Math.PI;
		double result = input * input * pi;
		System.out.printf("%.4f", result);
	}
}
