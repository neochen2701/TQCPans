import java.util.Scanner;

public class JPA305 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            int[] input = new int[3];
            input[0] = Integer.parseInt(scan.nextLine());
            input[1] = Integer.parseInt(scan.nextLine());
            input[2] = Integer.parseInt(scan.nextLine());
            System.out.print(compute(input));
        }
    }

    public static int compute(int[] input) {
        return input[1] == 1 ? input[0] + input[2] : input[0] * input[2];
    }
}