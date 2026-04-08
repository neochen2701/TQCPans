import java.util.Scanner;

public class JPA709 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        int line = Integer.parseInt(scan.nextLine());
        String[] input = new String[line];
        for (int i = 0; i < line; i++) {
            input[i] = scan.nextLine();
        }
        run(input);
    }

    public static void run(String[] input) {
        StringBuilder output = new StringBuilder();
        double sum = 0;
        int max = 0;
        for (String in : input) {
            sum += Integer.parseInt(in.split(" ")[2]) * Integer.parseInt(in.split(" ")[2]) * 3.14159;
            if (Integer.parseInt(in.split(" ")[2]) > max) {
                max = Integer.parseInt(in.split(" ")[2]);
            }
        }
        output.append("Sum = ").append(String.format("%.2f",Math.round(sum * 100.00) / 100.00)).append("\n");
        for (String in : input) {
            if (Integer.parseInt(in.split(" ")[2]) == max) {
                System.out.print(output.append("x: ")
                        .append(Integer.parseInt(in.split(" ")[0]))
                        .append(", ")
                        .append("y: ")
                        .append(Integer.parseInt(in.split(" ")[1]))
                        .append("\n")
                        .append("radius: ")
                        .append(max));
                break;
            }
        }
    }
}
