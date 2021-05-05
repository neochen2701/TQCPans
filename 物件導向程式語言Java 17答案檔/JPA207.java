import java.util.Scanner;

public class JPA02 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String input = sc.next();
		sc.close();

		char[] data = input.toCharArray();
		for (char item : data)
			System.out.println("ASCII code for " + "'" + item + "'" + " is " + (int) item);
	}
}
