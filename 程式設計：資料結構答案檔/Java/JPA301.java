import java.io.*;
import java.util.*;

class Player {
    int id;
    String name;
    int level;
    int score;

    public Player(int id, String name, int level, int score) {
        this.id = id;
        this.name = name;
        this.level = level;
        this.score = score;
    }
}

public class JPA301 {
    public static void main(String[] args) {
        List<Player> players = readCsvFile("read.csv");

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        if (n > players.size()) {
            System.out.println("Exceeds data upper limit");
        } else {
            Collections.sort(players, (p1, p2) -> {
                if (p2.score != p1.score) {
                    return Integer.compare(p2.score, p1.score);
                } else {
                    return Integer.compare(p2.id, p1.id);
                }
            });

            for (int i = 0; i < n; i++) {
                Player p = players.get(i);
                System.out.printf("%d | %d | %s | %d | %d\n", i + 1, p.id, p.name, p.level, p.score);
            }
        }
    }

    private static List<Player> readCsvFile(String filePath) {
        List<Player> players = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            br.readLine();
            while ((line = br.readLine()) != null) {
                String[] values = line.split(",");
                if (values.length == 4) {
                    int id = Integer.parseInt(values[0]);
                    String name = values[1];
                    int level = Integer.parseInt(values[2]);
                    int score = Integer.parseInt(values[3]);
                    players.add(new Player(id, name, level, score));
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading CSV file: " + e.getMessage());
        }
        return players;
    }
}
