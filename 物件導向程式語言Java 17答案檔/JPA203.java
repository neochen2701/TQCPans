import java.util.Scanner;

public class JPA02 {

	public static void main(String[] args) {

		int[] data = new int[3];
                Scanner sc = new Scanner(System.in);
		for (int i = 0; i < 3; i++) {
			int input;
			
			try {
				input = sc.nextInt();
			} catch (Exception e) {
				input = 0;
				if(sc.hasNext())
				   sc.next();
			}
			data[i] = input;
		}

		for (int o : data)
			if (o > 100)
				System.out.print("");
			else if (o >= 85)
				System.out.println("A");
			else if (o >= 60)
				System.out.println("B");
			else
				System.out.println("C");
	}
}
