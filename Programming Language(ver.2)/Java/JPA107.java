import java.util.Scanner;

public class JPA107 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            String[] input = new String[6];
            input[0] = scan.nextLine();
            input[1] = scan.nextLine();
            input[2] = scan.nextLine();
            input[3] = scan.nextLine();
            input[4] = scan.nextLine();
            input[5] = scan.nextLine();
            run(input);
        }
    }

    public static void run(String[] input) {
        // 前兩行
        int counter = 1;
        for (String in : input) {
            for (int i = 0; i < 10 - in.length(); i++) {
                System.out.print(" ");
            }
            System.out.print(in);

            if (counter % 3 == 0) {
                System.out.println();
            } else {
                System.out.print(" ");
            }
            counter++;
        }

        // 後兩行
        counter = 1;
        for (String in : input) {
            System.out.print(in);
            for (int i = 0; i < 10 - in.length(); i++) {
                System.out.print(" ");
            }

            if (counter != 6)
                if (counter == 3) {
                    System.out.println();
                } else {
                    System.out.print(" ");
                }
            counter++;
        }
    }
}
