import java.util.Scanner;

public class JPA506 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        int in = Integer.parseInt(input);
        StringBuilder output = new StringBuilder();
        for (int i = 2; i < Integer.parseInt(input); i++) {
            while (in % i == 0) {
                output.append(i).append("*");
                in /= i;
            }
            if (i > in) {
                break;
            }
        }
        System.out.print(output.length() == 0 ? "-1" : output.deleteCharAt(output.lastIndexOf("*")));

    }
}
