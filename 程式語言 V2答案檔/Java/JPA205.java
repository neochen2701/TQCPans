import java.util.Arrays;
import java.util.Scanner;

public class JPA205 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            String[] input = new String[10];
            for (int i = 0; i < 10; i++) {
                input[i] = scan.nextLine();
            }
            run(input);
        }
    }

    public static void run(String[] input) {
        System.out.println("number1:" + Arrays.stream(input).mapToInt(Integer::parseInt).filter(n -> n == 1).count());
        System.out.println("number2:" + Arrays.stream(input).mapToInt(Integer::parseInt).filter(n -> n == 2).count());
        System.out.println("number3:" + Arrays.stream(input).mapToInt(Integer::parseInt).filter(n -> n == 3).count());
        System.out.println("number4:" + Arrays.stream(input).mapToInt(Integer::parseInt).filter(n -> n == 4).count());
        System.out.println("number5:" + Arrays.stream(input).mapToInt(Integer::parseInt).filter(n -> n == 5).count());
        System.out.println("number6:" + Arrays.stream(input).mapToInt(Integer::parseInt).filter(n -> n == 6).count());
        System.out.print("error:" + Arrays.stream(input).mapToInt(Integer::parseInt).filter(n -> n < 1 || n > 6).count());
    }
}
