import java.util.Arrays;
import java.util.Scanner;

public class JPA307 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            int[] input = new int[5];
            input[0] = Integer.parseInt(scan.nextLine());
            input[1] = Integer.parseInt(scan.nextLine());
            input[2] = Integer.parseInt(scan.nextLine());
            input[3] = Integer.parseInt(scan.nextLine());
            input[4] = Integer.parseInt(scan.nextLine());
            System.out.print(compute(input));
        }
    }

    public static int compute(int[] input) {
        return Arrays.stream(input).max().getAsInt();
    }
}