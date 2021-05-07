import java.util.Scanner;

public class JPA02 {

	public static void main(String[] args) {

		int input = 0;
		try {
			Scanner sc = new Scanner(System.in);
			input = sc.nextInt();
			sc.close();
		} catch (Exception e) {
			System.out.println("error");
			return;
		}

		if ((input % 2) == 0)
             System.out.print(input + " is an even number.");
		else
             System.out.print(input + " is an odd number.");
	}


}