import java.util.Arrays;
import java.util.Scanner;

public class JPA103 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            String[] input = new String[3];
            input[0] = scan.nextLine();
            input[1] = scan.nextLine();
            input[2] = scan.nextLine();
            run(input);
        }
    }

    public static void run(String[] input) {
        int total = Arrays.stream(input).mapToInt(Integer::parseInt).sum();
        System.out.println(input[0] + "+" + input[1] + "+" + input[2] + "=" + total);
        System.out.print(String.format("%.2f", (float)total / 3));
    }
}
