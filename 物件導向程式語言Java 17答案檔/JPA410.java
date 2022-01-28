import java.util.Scanner;

public class JPA04 {

	public static void main(String[] args) {

		String[] birthday = { "1980/1/11", "1985/3/2", "1985/12/3", "1986/6/3", "1986/11/14", "1987/2/2", "1987/8/1",
				"1987/10/12", "1987/9/3", "1987/8/1", "1987/4/12", "1988/1/3", "1987/5/6", "1987/6/7", "1987/8/19",
				"1987/6/13", "1987/10/9", "1986/4/8", "1987/5/15", "1987/2/19", "1987/3/15", "1987/3/11", "1987/3/31" };
		int[] birthday2 = new int[birthday.length];
		for (int i = 0; i < birthday.length; i++)

		{
			birthday2[i] = Integer.parseInt(birthday[i].substring(5, 7).replace("/", ""));
		}
		try {
			Scanner sc = new Scanner(System.in);
			int com = sc.nextInt();
			sc.close();

			if (com > 12 || com < 1) {
				System.out.print("error");
				return;
			}

			int sum = 0;
			for (int com2 : birthday2) {
				if (com2 == com) {
					sum += 1;
				}
			}
			System.out.print(sum);
		} catch (Exception ex) {
			System.out.print("error");
			return;
		}
	}
}