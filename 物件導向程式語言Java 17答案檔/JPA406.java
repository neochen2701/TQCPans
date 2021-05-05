import java.util.Random;
import java.util.Scanner;

public class JPA04 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int number = 0;
		try {
			number = sc.nextInt();
			sc.close();
			if (number < 1 || number > 100) {
				System.out.print("error");
				System.exit(0);
			}

		} catch (Exception ex) {
			System.out.print("error");
			System.exit(1);
		}
		Random rand = new Random();
		rand.setSeed(number);
		int[] num = new int[10];
		for (int i = 0; i < 10; i++) {
			num[i] = rand.nextInt(100) + 1;
		}
		for (int show : num) {
			System.out.print(show + " ");
		}
	}
}
