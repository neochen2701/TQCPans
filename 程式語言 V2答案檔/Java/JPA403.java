import java.util.Scanner;

public class JPA403 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        for (int i = 0; i < input.length(); i++) {
            System.out.print(Character.isUpperCase(input.charAt(i)) ? Character.toLowerCase(input.charAt(i)) : Character.toUpperCase(input.charAt(i)));
        }
    }
}
