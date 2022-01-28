import java.util.Scanner;

public class JPA03 {

	public static void main(String[] args) {

		int[] scores = { 100, 100, 95, 95, 92, 91, 90, 100, 88, 88, 87, 87, 90, 91, 85, 80, 81, 82, 82, 89 };
		Scanner sc = new Scanner(System.in);
		double total = 0;
		double ave = 0;
		int num = 0;

		try {
			num = sc.nextInt();

		} catch (Exception e) {
		}
		sc.close();

		int len = 0;
		for (int i = 0; i < scores.length; i++) {
			if (scores[i] != num) {
				scores[len] = scores[i];
				len++;
			}
		}

		for (int i = 0; i < len; i++) {
			int chk = scores[i];
			total += chk;
		}
		ave = total / len;
		System.out.printf("%.2f", ave);
	}
}