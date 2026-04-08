import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class JPA710 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        int line = 10;
        String[] input = new String[line];
        for (int i = 0; i < line; i++) {
            input[i] = scan.nextLine();
        }
        run(input);
    }

    public static void run(String[] input) {
        StringBuilder output = new StringBuilder();
        int[] buffer = new int[4];
        buffer[0] = 0;
        buffer[1] = 0;
        buffer[2] = 0;
        buffer[3] = 0;
        List<Integer> list = new LinkedList<>(List.of(0, 0, 0, 0));
        for (String in : input) {
            if (!list.contains(Integer.parseInt(in))) {
                int re = 0;
                if (list.size() == 4) {
                    re = list.remove(0);
                }
                list.add(Integer.parseInt(in));
                for (int i = 0; i < buffer.length; i++) {
                    if (buffer[i] == re) {
                        buffer[i] = Integer.parseInt(in);
                        break;
                    }
                }
            }
            output.append(buffer[0])
                    .append(" ")
                    .append(buffer[1])
                    .append(" ")
                    .append(buffer[2])
                    .append(" ")
                    .append(buffer[3])
                    .append(" ")
                    .append("\n");
        }
        System.out.print(output.deleteCharAt(output.lastIndexOf("\n")));
    }
}
