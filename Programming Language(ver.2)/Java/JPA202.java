import java.util.Scanner;

public class JPA202 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        int inputInt = Integer.parseInt(input);
        if (inputInt > 90 || inputInt < 0) {
            System.out.print("error");
        } else {
            System.out.print(inputInt > 60 ? inputInt + 10 : inputInt + 5);
        }
    }
}
