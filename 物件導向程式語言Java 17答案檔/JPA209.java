import java.util.Scanner;

public class JPA02 {

	public static void main(String[] args) {

		try {
			String s1, s2;
			double x, y;

			Scanner sc = new Scanner(System.in);
			s1 = sc.next();
			x = Double.parseDouble(s1);
			s2 = sc.next();
			y = Double.parseDouble(s2);
			sc.close();

			if (x == 0.0 && y == 0.0)
				System.out.print("(" + s1 + "," + s2 + ")" + " origin");
			else if (x == 0.0)
				System.out.print("(" + s1 + "," + s2 + ")" + " Y");
			else if (y == 0.0)
				System.out.print("(" + s1 + "," + s2 + ")" + " X");
			else if (x > 0.0 && y > 0.0)
				System.out.print("(" + s1 + "," + s2 + ")" + " 1");
			else if (x < 0.0 && y > 0.0)
				System.out.print("(" + s1 + "," + s2 + ")" + " 2");
			else if (x < 0.0 && y < 0.0)
				System.out.print("(" + s1 + "," + s2 + ")" + " 3");
			else if (x > 0.0 && y < 0.0)
				System.out.print("(" + s1 + "," + s2 + ")" + " 4");
		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}