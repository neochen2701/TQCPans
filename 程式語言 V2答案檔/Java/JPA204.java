import java.util.Scanner;

public class JPA204 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            String[] input = new String[4];
            input[0] = scan.nextLine();
            input[1] = scan.nextLine();
            input[2] = scan.nextLine();
            run(input);
        }
    }

    public static void run(String[] input) {
        switch (input[2]) {
            case "+":
                System.out.print(input[0] + "+" + input[1] + "=" + (Integer.parseInt(input[0]) + Integer.parseInt(input[1])));
                break;
            case "-":
                System.out.print(input[0] + "-" + input[1] + "=" + (Integer.parseInt(input[0]) - Integer.parseInt(input[1])));
                break;
            case "*":
                System.out.print(input[0] + "*" + input[1] + "=" + (Integer.parseInt(input[0]) * Integer.parseInt(input[1])));
                break;
            default:
                System.out.print("error");
        }
    }
}
