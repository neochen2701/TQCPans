import java.util.Scanner;

public class JPA104 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            String[] input = new String[2];
            input[0] = scan.nextLine();
            input[1] = scan.nextLine();
            run(input);
        }
    }

    public static void run(String[] input) {
        String output = String.valueOf(Float.parseFloat(input[0]) + Float.parseFloat(input[1]));
        double filterOutput = (Math.round(Math.abs(Double.parseDouble(output)) * 100.0) / 100.0);
        if (Float.parseFloat(output) < 0) {
            filterOutput *= -1;
        }
        System.out.print("total=" + String.format("%.2f", (float)filterOutput));
    }
}
