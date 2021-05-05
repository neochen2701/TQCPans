import java.util.Scanner;

public class JPA01 {

	public static void main(String[] args) {
		String dreams = "There are moments in life when you miss someone so much that "
				+ "you just want to pick them from your dreams and hug them for real! Dream what "
				+ "you want to dream; go where you want to go; be what you want to be, because you have "
				+ "only one life and one chance to do all the things you want to do";

		Scanner sc = new Scanner(System.in);
		String search = sc.nextLine();
		sc.close();

		int len = search.length();
		int first = dreams.indexOf(search) + 1;
		int last = dreams.lastIndexOf(search) + 1;
		String result;

		if (first == 0) {
			result = "";
		}

		else if (first == last) {
			last = 0;
			result = dreams.substring(first - 1);
		} else {
			if (last == dreams.length() - len + 1)
				result = dreams.substring(first - 1);
			else
				result = dreams.substring(first - 1, last + len);
		}
		System.out.println("first:" + first);
		System.out.println("last:" + last);
		System.out.println("capture:" + result);
	}
}
