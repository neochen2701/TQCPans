import java.util.Scanner;

public class JPA401 {
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
        System.out.print(input[0].length() + "\n" + input[1].length() + "\n" + input[0] + input[1]);
    }
}
