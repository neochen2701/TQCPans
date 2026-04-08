import java.util.Arrays;
import java.util.Scanner;

public class JPA509 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        System.out.print(input.replaceAll("/", " ") + "\n" + Arrays.stream(input.split("/")).mapToInt(Integer::parseInt).sum());
    }
}
