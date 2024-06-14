import java.util.*;

public class JPA405 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		int s = sc.nextInt();
		int t = sc.nextInt();
		double[][] adjArrayOfGraph = new double[m + 1][m + 1];
		for (int i = 0; i < n; i++) {
			int v1 = sc.nextInt();
			int v2 = sc.nextInt();
			double w = sc.nextDouble();
			adjArrayOfGraph[v1][v2] = w;
			adjArrayOfGraph[v2][v1] = w;
		}
		sc.close();

		double[] distance = new double[m + 1];
		for (int i = 0; i < m + 1; i++) {
			distance[i] = Double.MAX_VALUE;
		}
		distance[s] = 0;

		boolean[] visited = new boolean[m + 1];
		for (int i = 0; i < m + 1; i++) {
			visited[i] = false;
		}

		visited[s] = true;
		for (int i = 1; i < m + 1; i++) {
			if (adjArrayOfGraph[s][i] != 0) {
				distance[i] = adjArrayOfGraph[s][i];
			}
		}

		for (int i = 0; i < m; i++) {
			int minIndex = -1;
			double minDistance = Double.MAX_VALUE;
			for (int j = 1; j < m + 1; j++) {
				if (visited[j] == false && distance[j] < minDistance) {
					minIndex = j;
					minDistance = distance[j];
				}
			}

			if (minIndex == -1) {
				break;
			}

			visited[minIndex] = true;
			for (int j = 1; j < m + 1; j++) {
				if (visited[j] == false && adjArrayOfGraph[minIndex][j] != 0) {
					if (distance[minIndex] + adjArrayOfGraph[minIndex][j] < distance[j]) {
						distance[j] = distance[minIndex] + adjArrayOfGraph[minIndex][j];
					}
				}
			}
		}

		System.out.printf("%.1f\n", distance[t]);
	}
}