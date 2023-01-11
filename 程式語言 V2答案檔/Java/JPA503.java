import java.util.Scanner;

public class JPA503 {
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
        StringBuilder output = new StringBuilder();
        Integer result = null;
        for (int i = 1; i < Integer.parseInt(input[0]); i++) {
            if (Math.round(Math.sqrt(i)) == Math.sqrt(i)) {
                result = Integer.parseInt(String.valueOf(Math.round(Math.sqrt(i))));
                int mul = result;
                for (int j = 1; j < Integer.parseInt(input[1]); j++) {
                    result *= mul;
                }
            }
            if (result != null) {
                output.append(result).append("\n");
                result = null;
            }
        }
        System.out.print(output.deleteCharAt(output.lastIndexOf("\n")));
    }
}
