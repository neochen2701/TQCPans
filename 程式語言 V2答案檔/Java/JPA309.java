import java.util.Arrays;
import java.util.Scanner;

public class JPA309 {
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
            System.out.print(String.format("%.3f", compute(input)));
        }
    }

    public static float compute(int[] input) {
        double[] result = new double[3];
        for (int i = 0; i < 3; i++) {
            result[i] = (double)input[i] / (double)input[i + 3];
        }
        return (float) Arrays.stream(result).min().getAsDouble();
    }
}