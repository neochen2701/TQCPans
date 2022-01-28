import java.util.Scanner;

public class JPA03 {

	static int sum = 0;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int ans = 0;
		try {
			ans = sc.nextInt();
		} catch (Exception e) {
			System.out.print("error");
			return;
		}
		sc.close();

		ans = Math.abs(ans);
		if (ans <= 0) {
			System.out.print("error");
			return;
		}
		System.out.print(compute(ans));
	}

	public static int compute(int i) {
		if (i == 1)
			return 2;
		else {
			sum = sum + compute(i - 1) + 3 * i;
			return sum;
		}
	}
}