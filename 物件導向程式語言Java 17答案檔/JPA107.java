import java.util.Scanner;

public class JPA01 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		float n1 = 0, n2 = 0, n3 = 0;

		try {
			n1 = sc.nextFloat();
			if (n1 > 100) {
				n1 = 100;
			} else if (n1 < 0) {
				n1 = 0;
			}
		} catch (Exception e) {
			n1 = 0;
			sc.next();
		}

		try {
			n2 = sc.nextFloat();
			if (n2 > 100) {
				n2 = 100;
			} else if (n1 < 0) {
				n2 = 0;
			}
		} catch (Exception e) {
			n2 = 0;
			sc.next();
		}

		try {
			n3 = sc.nextFloat();
			if (n3 > 100) {
				n3 = 100;
			} else if (n1 < 0) {
				n3 = 0;
			}
		} catch (Exception e) {
			n3 = 0;
		}
		sc.close();
		int ave = (int) (n1 + n2 + n3) / 3;
		if (ave == 100) {
			System.out.print("full mark:" + ave);
		} else if (ave > 60) {
			System.out.print("pass:" + ave);
		} else {
			System.out.print("failed:" + ave);
		}
	}
}
