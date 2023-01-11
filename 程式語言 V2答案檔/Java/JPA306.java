import java.util.Scanner;

public class JPA306 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            int input = Integer.parseInt(scan.nextLine());
            System.out.print(input + "!=" + compute(input));
        }
    }

    public static int compute(int input) {
        if (input == 0) return 1;
        else return input * compute(input - 1);
    }
}
