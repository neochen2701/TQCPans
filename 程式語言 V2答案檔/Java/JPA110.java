import java.util.Scanner;

public class JPA110 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            String[] input = new String[6];
            input[0] = scan.nextLine();
            input[1] = scan.nextLine();
            input[2] = scan.nextLine();
            run(input);
        }
    }

    public static void run(String[] input) {
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);
        int c = Integer.parseInt(input[2]);

        // part1
        if (a >= 60 && a < 100) {
            System.out.println("1");
        } else {
            System.out.println("0");
        }

        // part2
        System.out.println(String.format("%.2f", ((float) b + 1) / 10));

        // part3
        System.out.print(Math.max(a, c));
    }
}
