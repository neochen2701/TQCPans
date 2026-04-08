import java.util.Scanner;

public class JPA406 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        String upper = "QWERTYUIOPPASDFGHJKLLZXCVBNMM";
        String lower = "qwertyuioppasdfghjkllzxcvbnmm";
        for (char i : input.toCharArray()) {
            if (upper.chars().filter(c -> c == Character.toUpperCase(i)).count() == 1) {
                System.out.print(Character.isUpperCase(i) ? upper.charAt(upper.indexOf(i) + 1) : lower.charAt(lower.indexOf(i) + 1));
            } else {
                System.out.print(i);
            }
        }
    }
}
