import java.util.Scanner;

public class JPA303 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            int input = Integer.parseInt(scan.nextLine());
            System.out.print(input + " is" + (compute(input) == 1 ? "" : " not") + " a prime number");
        }
    }

    public static int compute(int input) {
        int count = 0;
        for (int i = 2; i <= input; i++) {
            if (input % i == 0) {
                count++;
            }
        }
        return count == 1 ? 1 : 0;
    }
}
