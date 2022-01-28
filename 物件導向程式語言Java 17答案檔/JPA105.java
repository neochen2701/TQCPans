import java.util.Scanner;

public class JPA01 {

	public static void main(String[] args) {
		String dreams = "There are moments in life when you miss someone so much that "
				+ "you just want to pick them from your dreams and hug them for real! Dream what "
				+ "you want to dream;go where you want to go;be what you want to be,because you have "
				+ "only one life and one chance to do all the things you want to do";

		Scanner sc = new Scanner(System.in);
		String search = sc.nextLine();
		sc.close();

		// TO DO
		int first = dreams.indexOf(search);
		int last = dreams.lastIndexOf(search);
		String result = "";

		if (first == -1 || last == -1) {
			first = 0;
			last = 0;
		} else {
			if (first == last) {
				result = dreams.substring(first, dreams.length());
				first += 1;
				last = 0;
			} else {
				result = dreams.substring(first, last + search.length());
				first += 1;
				last += 1;
			}
		}
		System.out.println("first:" + first);
		System.out.println("last:" + last);
		System.out.print("capture:" + result);
	}
}
