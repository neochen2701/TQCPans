import java.util.Arrays;
import java.util.Scanner;

public class JPA605 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        String[] input = new String[6];
        for (int i = 0; i < 6; i++) {
            input[i] = scan.nextLine();
        }
        run(input);
    }

    public static void run(String[] input) {
        int[] inputList = Arrays.stream(input).mapToInt(Integer::parseInt).sorted().toArray();
        System.out.print((inputList[3] + inputList[4] + inputList[5]) - (inputList[0] + inputList[1] + inputList[2]));
    }
}
