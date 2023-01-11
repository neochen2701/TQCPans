import java.util.Scanner;

public class JPA603 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        String size = scan.nextLine();
        int x = Integer.parseInt(size.split(" ")[0]);
        String[] input = new String[x + 1];
        for (int i = 1; i <= x; i++) {
            input[i] = scan.nextLine();
        }
        input[0] = size;
        run(input);
    }

    public static void run(String[] input) {
        for (int i = 1; i < input.length; i++) {
            System.out.print(input[i].replaceAll(" ", ","));
            if (i != input.length - 1) {
                System.out.println();
            }
        }
    }
}
