import java.util.Scanner;

public class JPA03 {

	public static void main(String[] args) {

		long[] n = new long[50];
		n[0] = 0;
		n[1] = 1;

		for (int a = 2; a < 50; a++)
			n[a] = n[a - 1] + n[a - 2];

		try {
			Scanner sc = new Scanner(System.in);
			int input = sc.nextInt();
			sc.close();

			if (input < 50)
				System.out.print((input + 1) + ":" + n[input]);
			else {
				System.out.print("error");
				return;
			}
		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}