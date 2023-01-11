import java.util.Scanner;

public class JPA602 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        run(scan.nextLine());
    }

    public static void run(String input) {
        StringBuilder U = new StringBuilder();
        StringBuilder L = new StringBuilder();
        for (char in : input.toCharArray()) {
            if (Character.isUpperCase(in)) {
                U.append(in);
            } else {
                L.append(in);
            }
        }
        System.out.println(U);
        System.out.println(L);
        System.out.print(U.length());

    }
}
