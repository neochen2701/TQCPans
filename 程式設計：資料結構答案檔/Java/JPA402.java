import java.util.*;

public class JPA402 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		int[][] adjArrayOfGraph = new int[m + 1][m + 1];
		for (int i = 0; i < n; i++) {
			int v1 = sc.nextInt();
			int v2 = sc.nextInt();
			adjArrayOfGraph[v1][v2] = 1;
			adjArrayOfGraph[v2][v1] = 1;
		}
		sc.close();

		int[] degreeOfVertex = new int[m + 1];
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				if (adjArrayOfGraph[i][j] == 1) {
					degreeOfVertex[i]++;
				}
			}
		}

		int numOfOddDegreeVertex = 0;
		for (int i = 1; i <= m; i++) {
			if (degreeOfVertex[i] % 2 == 1) {
				numOfOddDegreeVertex++;
			}
		}

		if (numOfOddDegreeVertex == 0 || numOfOddDegreeVertex == 2) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j < m; j++) {
				System.out.print(adjArrayOfGraph[i][j] + " ");
			}
			System.out.println(adjArrayOfGraph[i][m]);
		}
	}
}