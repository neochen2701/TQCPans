import java.util.Scanner;

public class JPA03 {

	public static void main(String[] args) {

		int[] scores = { 100, 100, 95, 95, 92, 91, 90, 100, 88, 88, 87, 87, 90, 91, 85, 80, 81, 82, 82, 89 };
		int input;
		int total = 0;
		try {
			Scanner sc = new Scanner(System.in);
			input = sc.nextInt();
			sc.close();

			for (int chk : scores)
				if (chk == input)
					total += 1;
			System.out.print(total);
		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}