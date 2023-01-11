import java.io.*;
import java.net.URISyntaxException;
import java.util.*;

public class JPA707 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        int line = Integer.parseInt(scan.nextLine());
        String[] input = new String[line];
        for (int i = 0; i < line; i++) {
            input[i] = scan.nextLine();
        }
        run(input);
    }

    public static void run(String[] input) {
        StringBuilder output = new StringBuilder();
        Map<String, Integer> map = new HashMap<>();
        Arrays.stream(input).forEach(in -> map.put(in.replace(" ", "x"), Integer.parseInt(in.split(" ")[0]) * Integer.parseInt(in.split(" ")[1])));
        map.entrySet().stream().sorted(Map.Entry.comparingByValue()).forEach(en->{
            output.append(en.getKey()).append("=").append(en.getValue()).append("\n");
        });
        System.out.print(output.deleteCharAt(output.lastIndexOf("\n")));;
    }
}
