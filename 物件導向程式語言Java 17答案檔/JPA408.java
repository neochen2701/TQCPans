import java.util.Scanner;

public class JPA04 {

	public static void main(String[] args) {

		try {
			Scanner sc = new Scanner(System.in);
			String data1 = sc.next();
			sc.close();

			String[] data = data1.split(":");

			int day = Integer.parseInt(data[0]) / 8;
			int hour = Integer.parseInt(data[0]) % 8;
			int min = Integer.parseInt(data[1]);
			if (min > 60) {
				System.out.print("error");
				return;
			}

			System.out.print(day + "d:" + hour + "h:" + min + "m");

		} catch (Exception ex) {
			System.out.print("error");
			return;
		}
	}
}