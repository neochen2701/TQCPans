import java.util.*;

public class JPA704 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        int line = Integer.parseInt(scan.nextLine());
        run(line, scan.nextLine());
    }

    public static void run(int line, String input) {
        Map<String, Integer> map = new HashMap<>();
        Arrays.stream(input.split(" ")).forEach(in -> {
            map.merge(in, 1, Integer::sum);
        });
        if (line / 2 < Collections.max(map.values())) {
            for (Map.Entry<String, Integer> entry : map.entrySet()) {
                if (Objects.equals(entry.getValue(), Collections.max(map.values()))) {
                    System.out.print(entry.getKey());
                    break;
                }
            }
        } else {
            System.out.print("error");
        }
    }
}
