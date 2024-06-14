import java.io.*;
import java.util.*;

public class JPA401 {
    public static void main(String[] args) {
        String filename = "read.txt";
        try {
            int[][] graph = getGraphFromFile(filename);
            int numVertices = graph.length;
            int[] degrees = new int[numVertices];
            int maxWeight = 0;
            int minWeight = Integer.MAX_VALUE;

            for (int i = 0; i < numVertices; i++) {
                int degree = 0;
                int weightSum = 0;
                for (int j = 0; j < numVertices; j++) {
                    if (graph[i][j] > 0) {
                        degree++;
                        weightSum += graph[i][j];
                    }
                }
                degrees[i] = degree;
                maxWeight = Math.max(maxWeight, weightSum);
                minWeight = Math.min(minWeight, weightSum);
            }

            System.out.print("Degree:");
            for (int i = 0; i < numVertices - 1; i++) {
                System.out.print(degrees[i] + ",");
            }
            System.out.println(degrees[numVertices - 1]);
            System.out.println(maxWeight - minWeight);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static int[][] getGraphFromFile(String filename) throws IOException {
        List<String> lines = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                lines.add(line);
            }
        }

        int numVertices = lines.get(0).split(",").length;
        int[][] graph = new int[numVertices][numVertices];

        for (int i = 0; i < lines.size(); i++) {
            String[] parts = lines.get(i).split(",");
            for (int j = 0; j < parts.length; j++) {
                graph[i][j] = Integer.parseInt(parts[j]);
            }
        }

        return graph;
    }
}
