import java.util.Scanner;

public class JPA508 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        String[] input = new String[2];
        input[0] = scan.nextLine();
        input[1] = scan.nextLine();
        run(input);
    }

    public static void run(String[] input) {
        int total = Integer.valueOf(input[0], 2) + Integer.valueOf(input[1], 2);
        System.out.println(Integer.valueOf(input[0], 2) + " + " + Integer.valueOf(input[1], 2) + " = " + total);
        System.out.print(total > 255 ? "11111111" : String.format("%08d", Integer.parseInt(Integer.toBinaryString(total))));
    }
}
