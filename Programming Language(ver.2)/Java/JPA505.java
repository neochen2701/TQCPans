import java.util.Scanner;

public class JPA505 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        String[] input = new String[6];
        input[0] = scan.nextLine();
        input[1] = scan.nextLine();
        input[2] = scan.nextLine();
        input[3] = scan.nextLine();
        input[4] = scan.nextLine();
        input[5] = scan.nextLine();
        run(input);
    }

    public static void run(String[] input) {
        double result;
        result = Math.abs(Double.parseDouble(input[0])) * Math.floor(Double.parseDouble(input[1]));
        result += Math.pow(Double.parseDouble(input[2]), Double.parseDouble(input[3])) * Math.sqrt(Double.parseDouble(input[4]));
        result += Math.log10(Double.parseDouble(input[5]));
        System.out.print(String.format("%.2f", Math.round(result * 100.0) / 100.0));
    }
}
