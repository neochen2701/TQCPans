import java.util.Scanner;

public class JPA02 {

	public static void main(String[] args) {

		final String dreams = "There are moments in life when you miss someone so much that "
				+ "you just want to pick them from your dreams and hug them for real! Dream what "
				+ "you want to dream; go where you want to go; be what you want to be, because you have "
				+ "only one life and one chance to do all the things you want to do";

		Scanner sc = new Scanner(System.in);
		String search = sc.nextLine();
		sc.close();

		int count = 0;
		int index = dreams.indexOf(search);

		while (index != -1) {
			index = search.length() + index;
			count++;
			index = dreams.indexOf(search, index);
		}
		System.out.print(count);
	}
}
