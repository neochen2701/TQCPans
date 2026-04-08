import java.util.Scanner;

public class JPA408 {
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
        if (input[0].length() <= 3 || input[0].length() > 20 || input[1].length() <= 3 || input[1].length() > 20) {
            System.out.print("error");
        } else {
            System.out.print(input[0].length() + "\n" + input[1].length() + "\n" + (new StringBuilder(input[0] + input[1])).reverse());
        }
    }
}
