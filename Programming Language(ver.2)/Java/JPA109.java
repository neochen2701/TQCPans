import java.util.Scanner;

public class JPA109 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        int inputInt = Integer.parseInt(input);
        if (inputInt < 0 || inputInt > 100) {
            System.out.print("error");
        } else {
            if (inputInt < 60) {
                System.out.println("fail");
            } else {
                System.out.println("pass");
            }

            if (inputInt % 2 == 0) {
                System.out.print("even");
            } else {
                System.out.print("odd");
            }
        }
    }
}
