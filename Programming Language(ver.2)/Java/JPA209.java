import java.util.Scanner;

public class JPA209 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        if (Integer.parseInt(input) != 0 && Integer.parseInt(input) != 1) {
            System.out.print("error");
            return;
        }
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++) {
                if (Integer.parseInt(input) == 0) {
                    System.out.print(i + " x " + j + " = " + i * j + "\t");
                } else {

                    System.out.print(j + " x " + i + " = " + i * j + "\t");
                }
            }
            System.out.println();
        }
    }
}
