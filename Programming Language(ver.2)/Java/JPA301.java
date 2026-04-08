import java.util.Scanner;

public class JPA301 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            int[] input = new int[2];
            input[0] = Integer.parseInt(scan.nextLine());
            input[1] = Integer.parseInt(scan.nextLine());
            System.out.print(compute(input));
        }
    }

    public static int compute(int[] input) {
        int out = 0;
        for (int j = 0; j < input[1]; j++) {
            for (int i = 0; i < input[0]; i++) {
                System.out.print("*");
            }
            System.out.println();
            if (j == input[1] - 1) {
                out = input[0] * input[1];
                break;
            }
        }
        return out;
    }
}
