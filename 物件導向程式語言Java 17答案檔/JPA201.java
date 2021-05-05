import java.util.Scanner;

public class JPA02 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String s1 = sc.next();
		String s2 = sc.next();
		sc.close();

		double num1 = 0, num2 = 0;
		try {
			num1 = Double.parseDouble(s1);
		} catch (Exception e) {
			num1 = 0;
			s1 = "0";
		}
		try {
			num2 = Double.parseDouble(s2);
		} catch (Exception e) {
			num2 = 0;
			s2 = "0";
		}
		if (num1 > num2)
			System.out.print(s1 + ">" + s2);
		else if (num1 < num2)
			System.out.print(s1 + "<" + s2);
		else
			System.out.print(s1 + "=" + s2);
	}
}
