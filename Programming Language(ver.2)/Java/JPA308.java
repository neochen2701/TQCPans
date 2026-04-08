import java.util.Scanner;

public class JPA308 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            for (int i = Integer.parseInt(scan.nextLine()); i >= 1; i--) {
                System.out.println("fib(" + i + ")=" + compute(i));
            }
        }
    }

    public static int compute(int input) {
        return input >= 2 ? compute(input - 2) + compute(input - 1) : input;
    }
}
