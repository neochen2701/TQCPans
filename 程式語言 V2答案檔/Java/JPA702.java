import java.util.Arrays;
import java.util.Scanner;

public class JPA702 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        run(scan.nextLine());
    }

    public static void run(String input) {
        System.out.print(Integer.valueOf(input,2));
    }
}
