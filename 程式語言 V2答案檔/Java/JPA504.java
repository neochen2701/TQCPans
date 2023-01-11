import java.util.Scanner;

public class JPA504 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        System.out.print((new StringBuilder(input)).reverse().toString().equals(input) ? "Yes" : "No");
    }
}
