import java.util.Scanner;

public class JPA210 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            String[] input = new String[2];
            input[0] = scan.nextLine();
            input[1] = scan.nextLine();
            run(input);
        }
    }

    public static void run(String[] input) {
        int min = Math.min(Integer.parseInt(input[0]), Integer.parseInt(input[1]));
        int max = Math.max(Integer.parseInt(input[0]), Integer.parseInt(input[1]));
        int commonFactor = 0, commonMultiple = 0;
        for (int i = 1; ; i++) {
            if (i <= min) {
                if (min % i == 0 && max % i == 0) {
                    commonFactor = i;
                }
            }
            if (i >= max) {
                if (i % min == 0 && i % max == 0) {
                    commonMultiple = i;
                    break;
                }
            }
        }
        System.out.print(commonFactor + "\n" + commonMultiple);
    }
}
