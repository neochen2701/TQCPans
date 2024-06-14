import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class JPA403 {

    private static class Pair {
        int node;
        int weight;

        Pair(int node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int v = scanner.nextInt();
        int threshold = scanner.nextInt();

        boolean[] visited = new boolean[n + 1];
        ArrayList<ArrayList<Pair>> node = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            node.add(new ArrayList<>());
        }

        for (int i = 0; i < n - 1; i++) {
            int v0 = scanner.nextInt();
            int v1 = scanner.nextInt();
            int w = scanner.nextInt();
            node.get(v0).add(new Pair(v1, w));
            node.get(v1).add(new Pair(v0, w));
        }

        visited[v] = true;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(v, Integer.MAX_VALUE));

        int ans = 0;
        while (!q.isEmpty()) {
            Pair t = q.poll();

            for (Pair p : node.get(t.node)) {
                if (!visited[p.node]) {
                    visited[p.node] = true;
                    int minWeight = Math.min(t.weight, p.weight);
                    if (minWeight >= threshold) {
                        ans++;
                        q.add(new Pair(p.node, minWeight));
                    }
                }
            }
        }

        System.out.println(ans);
    }
}
