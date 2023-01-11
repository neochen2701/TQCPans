import java.util.Scanner;

public class JPA207 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        int count = 0;
        for (int i = 2; i <= Integer.parseInt(input); i++) {
            if (Integer.parseInt(input) % i == 0) {
                count++;
            }
        }
        System.out.print(input + " is" + (count == 1 ? "" : " not") + " a prime number");
    }
}
