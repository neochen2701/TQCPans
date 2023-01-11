import java.util.Arrays;
import java.util.Scanner;

public class JPA604 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        String[] input = new String[9];
        for (int i = 0; i < 9; i++) {
            input[i] = scan.nextLine();
        }
        run(input);
    }

    public static void run(String[] input) {
        int[] inputList = Arrays.stream(input).mapToInt(Integer::parseInt).sorted().toArray();
        Arrays.stream(inputList).forEach(System.out::println);
        System.out.print("sum = " + Arrays.stream(inputList).sum());
    }
}
