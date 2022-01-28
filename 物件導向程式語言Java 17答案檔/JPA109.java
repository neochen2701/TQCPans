import java.util.Scanner;

public class JPA01 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String input = sc.next();
		sc.close();

		int first = input.charAt(0);
		if (input.length() == 1) {
			if (first == 57) {
				first = 48;
			} else if (first > 47 && first < 57) {
				first += 1;
			} else if (first >= 65 && first <= 90) {
				first += 33;
			} else if (first >= 97 && first <= 122) {
				first -= 31;
			} else {
				System.out.print("error");
				return;
			}
			System.out.print((char) first);
			return;
		}

		int last = input.charAt(input.length() - 1);
		String other = input.substring(1, input.length() - 1);

		if (first == 57) {
			first = 48;
		} else if (first > 47 && first < 57) {
			first += 1;
		} else if (first >= 65 && first <= 90) {
			first += 33;
		} else if (first >= 97 && first <= 122) {
			first -= 31;
		} else {
			System.out.print("error");
			return;
		}

		if (last == 57) {
			last = 48;
		} else if (last > 47 && last < 57) {
			last += 1;
		} else if (last >= 65 && last <= 90) {
			last += 33;
		} else if (last >= 97 && last <= 122) {
			last -= 31;
		} else {
			System.out.print("error");
			return;
		}

		System.out.print((char) first + other + (char) last);

	}
}
