import java.util.Arrays;
import java.util.Scanner;

public class JPA304 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            int[] input = new int[6];
            input[0] = Integer.parseInt(scan.nextLine());
            input[1] = Integer.parseInt(scan.nextLine());
            input[2] = Integer.parseInt(scan.nextLine());
            input[3] = Integer.parseInt(scan.nextLine());
            input[4] = Integer.parseInt(scan.nextLine());
            input[5] = Integer.parseInt(scan.nextLine());
            System.out.print(compute(input));
        }
    }

    public static int compute(int[] input) {
        return (int) (Arrays.stream(input).filter(in -> in % 3 == 0).count());
    }
}