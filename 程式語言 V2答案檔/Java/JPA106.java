import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

public class JPA106 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            String[] input = new String[4];
            input[0] = scan.nextLine();
            input[1] = scan.nextLine();
            input[2] = scan.nextLine();
            input[3] = scan.nextLine();
            run(input);
        }
    }

    public static void run(String[] input) {
        int[] inputInt = Arrays.stream(input).mapToInt(Integer::parseInt).toArray();
        int x = inputInt[2] - inputInt[0];
        int y = inputInt[3] - inputInt[1];

        double output = x * x + y * y;
        double filterOutput = (Math.round(Math.sqrt(output) * 100.0) / 100.0);
        System.out.print(String.format("%.2f", (float) filterOutput));
    }
}
