import java.util.Scanner;

public class JPA201 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        System.out.print(Integer.parseInt(input) % 2 == 0 ? "even" : "odd");
    }
}
