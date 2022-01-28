import java.util.Scanner;

public class JPA03 {

	public static void main(String[] args) {

		int[] n = new int[5];
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			try {
				n[i] = (int) sc.nextFloat();

			} catch (Exception e) {
				n[i] = 0;
				sc.next();
			}
		}
		sc.close();
		compute(n);
	}

	public static void compute(int[] n) {

		int count = 0, sum = 0;
		for (int i = 0; i < 5; i++) {

			if (n[i] > 50) {
				count++;
				sum += n[i];
			}
		}

		if (count == 0) {
			System.out.println("0");
			System.exit(0);
		} else {
			System.out.println(sum);
			System.out.println(sum / count);
		}
	}
}