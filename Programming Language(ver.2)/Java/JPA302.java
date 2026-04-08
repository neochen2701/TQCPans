import java.util.Scanner;

public class JPA302 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            System.out.print(compute(Integer.parseInt(scan.nextLine())));
        }
    }

    public static int compute(int input) {
        if (input < 0 || input > 100) {
            return -1;
        } else {
            return input < 60 ? input + 10 : input + 5;
        }
    }
}
