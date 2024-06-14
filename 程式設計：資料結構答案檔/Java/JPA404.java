import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Vertex {
    int id;
    List<Integer> neighbors;

    public Vertex(int id) {
        this.id = id;
        this.neighbors = new ArrayList<>();
    }
}

class Graph {
    List<Vertex> vertices;

    public Graph() {
        this.vertices = new ArrayList<>();
    }

    public int getIndex(int id) {
        for (int i = 0; i < this.vertices.size(); i++) {
            if (this.vertices.get(i).id == id) return i;
        }
        return -1;
    }

    public void addEdge(int u, int v) {
        int uIndex = getIndex(u);
        int vIndex = getIndex(v);
        if (uIndex == -1) {
            Vertex uVertex = new Vertex(u);
            uVertex.neighbors.add(v);
            this.vertices.add(uVertex);
        } else {
            this.vertices.get(uIndex).neighbors.add(v);
        }
        if (vIndex == -1) {
            Vertex vVertex = new Vertex(v);
            vVertex.neighbors.add(u);
            this.vertices.add(vVertex);
        } else {
            this.vertices.get(vIndex).neighbors.add(u);
        }
    }
}

public class JPA404 {
    private static void findAllPaths(Graph graph, int start, int end, List<Integer> path, List<List<Integer>> allPaths) {
        path.add(start);
        if (start == end) {
            allPaths.add(new ArrayList<>(path));
        } else {
            int startIndex = graph.getIndex(start);
            for (int neighbor : graph.vertices.get(startIndex).neighbors) {
                if (!path.contains(neighbor)) {
                    findAllPaths(graph, neighbor, end, path, allPaths);
                }
            }
        }
        path.remove(path.size() - 1);
    }

    private static List<Integer> getMaxPath(List<List<Integer>> allPaths) {
        List<Integer> maxPath = null;
        int maxLength = 0, maxPoint = 0;
        for (List<Integer> path : allPaths) {
            int length = path.size();
            int sum = path.stream().mapToInt(Integer::intValue).sum();
            if (maxLength < length || (maxLength == length && maxPoint <= sum)) {
                maxLength = length;
                maxPoint = sum;
                maxPath = path;
            }
        }
        return maxPath;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        Graph graph = new Graph();
        for (int i = 0; i < m; i++) {
            int x1 = scanner.nextInt();
            int x2 = scanner.nextInt();
            graph.addEdge(x1, x2);
        }
        int startN = scanner.nextInt();
        int endN = scanner.nextInt();
        List<Integer> path = new ArrayList<>();
        List<List<Integer>> allPaths = new ArrayList<>();
        findAllPaths(graph, startN, endN, path, allPaths);
        List<Integer> maxPath = getMaxPath(allPaths);
        for (int i = 0; i < maxPath.size(); i++) {
            System.out.print(maxPath.get(i));
            if (i < maxPath.size() - 1) System.out.print(" ");
        }
        System.out.println();
        scanner.close();
    }
}
