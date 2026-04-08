import java.util.Scanner;

public class JPA206 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            String[] input = new String[2];
            input[0] = scan.nextLine();
            input[1] = scan.nextLine();
            run(input);
        }
    }

    public static void run(String[] input) {
        int result = 0;
        for (int i = Integer.parseInt(input[0]); i <= Integer.parseInt(input[1]); i++) {
            if (i % 2 != 0) {
                result += i;
            }
        }
        System.out.print(result);
    }
}
