import java.util.*;
import java.util.Scanner;

public class JPA204 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		sc.close();

		Queue<Integer> allIds = new LinkedList<>();
		for (int i = 1; i <= n; i++)
			allIds.add(i);

		while (allIds.size() > 1) {
			for (int i = 1; i < x; i++) {
				int t = allIds.remove();
				allIds.add(t);
			}
			allIds.remove();
		}
		System.out.printf("%d\n", allIds.remove());
	}
}