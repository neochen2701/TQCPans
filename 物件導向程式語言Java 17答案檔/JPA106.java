import java.util.Scanner;

public class JPA01 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n1 = 0, n2 = 0, n3 = 0, n4 = 0;

		try {
			n1 = sc.nextInt();

		} catch (Exception e) {
			sc.next();
		}
		try {
			n2 = sc.nextInt();

		} catch (Exception e) {
			sc.next();
		}
		try {
			n3 = sc.nextInt();

		} catch (Exception e) {
			sc.next();
		}
		try {
			n4 = sc.nextInt();

		} catch (Exception e) {
			sc.next();
		}
		sc.close();

		int com1 = Math.max(n1, n2);
		int com2 = Math.max(com1, n3);
		int biggest = Math.max(com2, n4);
		com1 = Math.min(n1, n2);
		com2 = Math.min(com1, n3);
		int smallest = Math.min(com2, n4);
		if (smallest < 0) {
			smallest = 0;
		}

        System.out.println("smallest:" + smallest);
		System.out.print("largest:" + biggest);
	}

}
