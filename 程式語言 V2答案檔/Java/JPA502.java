import java.util.Arrays;
import java.util.Scanner;

public class JPA502 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        int[] inputList = Arrays.stream(input.split("")).mapToInt(Integer::parseInt).toArray();
        int total = 1;
        for (int i = 0; i < input.length(); i++) {
            total *= inputList[i];
            System.out.print(inputList[i]);
            if (i < input.length() - 1) {
                System.out.print("*");
            }
        }
        System.out.print("=" + total);
    }
}
