import java.util.Scanner;

public class JPA703 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        run(scan.nextLine());
    }

    public static void run(String input) {
        int[] result = new int[4];
        result[0] = Integer.parseInt(input) / 50;
        result[1] = (Integer.parseInt(input) % 50) / 10;
        result[2] = (Integer.parseInt(input) % 10) / 5;
        result[3] = Integer.parseInt(input) % 5;
        StringBuilder output = new StringBuilder()
                .append(result[0] == 0 ? "" : (result[0] + "*$50 "))
                .append(result[1] == 0 ? "" : (result[1] + "*$10 "))
                .append(result[2] == 0 ? "" : (result[2] + "*$5 "))
                .append(result[3] == 0 ? "" : (result[3] + "*$1 "));
        System.out.print(output.deleteCharAt(output.lastIndexOf(" ")));
    }
}
