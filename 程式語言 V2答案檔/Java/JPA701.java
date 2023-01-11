import java.util.Arrays;
import java.util.Scanner;

public class JPA701 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        int line = 3;
        String[] input = new String[line];
        for (int i = 0; i < line; i++) {
            input[i] = scan.nextLine();
        }
        run(input);
    }

    public static void run(String[] input) {
        int[] inputInt = Arrays.stream(input).mapToInt(Integer::parseInt).toArray();
        double s = Double.parseDouble(String.valueOf(inputInt[0] + inputInt[1] + inputInt[2])) / 2f;
        double result = Math.sqrt(s * (s - inputInt[0]) * (s - inputInt[1]) * (s - inputInt[2]));
        System.out.print(String.format("%.2f", Math.round(result * 100.00) / 100.00));
    }
}
