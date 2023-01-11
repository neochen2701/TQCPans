import java.util.Scanner;

public class JPA310 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            System.out.print(compute(Integer.parseInt(scan.nextLine())));
        }
    }

    public static int compute(int input) {
        int total = 0;
        int number;
        for (int i = 1; i < input; i++) {
            if (i / 100 != 0) {
                number = (i / 100) * (i / 100) * (i / 100) + (i % 100 / 10) * (i % 100 / 10) * (i % 100 / 10) + (i % 10) * (i % 10) * (i % 10);
            } else if (i / 10 != 0) {
                number = (i / 10) * (i / 10) + (i % 10) * (i % 10);
            } else {
                number = i;
            }

            if (i == number) {
                total += i;
                System.out.println(i);
            }
        }
        return total;
    }
}
