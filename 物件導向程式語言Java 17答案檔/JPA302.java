import java.util.Scanner;

public class JPA03 {

	public static void main(String[] args) {

		try {
			Scanner sc = new Scanner(System.in);
			int day = sc.nextInt();
			sc.close();

			String[] weeks = { "Mon", "Tus", "Wed", "Thr", "Fri", "Sat", "Sun" };
			if (day >= 0 && day < 7)
				System.out.print(weeks[day]);
			else {
				System.out.print("error");
				System.exit(0);
			}
		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}
