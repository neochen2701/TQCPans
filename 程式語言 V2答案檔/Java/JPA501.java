import java.util.Scanner;

public class JPA501 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        System.out.print(input + " change to " + input.substring(0, input.lastIndexOf(".") == -1 ? input.length() : input.lastIndexOf(".")));
    }
}
