import java.util.Scanner;

public class JPA402 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            String[] input = new String[3];
            input[0] = scan.nextLine();
            input[1] = scan.nextLine();
            input[2] = scan.nextLine();
            run(input);
        }
    }

    public static void run(String[] input) {
        if (Integer.parseInt(input[2]) > input[0].length()) {
            System.out.print("error");
        } else {
            int check = input[0].substring(0, Integer.parseInt(input[2])).compareTo(input[1].substring(0, Integer.parseInt(input[2])));
            System.out.print(input[0] + " " + (check == 0 ? "=" : (check > 0 ? ">" : "<")) + " " + input[1]);
        }
    }
}
