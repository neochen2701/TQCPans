import java.util.Scanner;

public class JPA708 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        int line = 3;
        String[] input = new String[line];
        for (int i = 0; i < line; i++) {
            input[i] = scan.nextLine();
        }
        run(input);
    }

    public static void run(String[] input) {
        StringBuilder output = new StringBuilder();
        int count = 0;
        for (String in : input) {
            if (Integer.parseInt(in.split(" ")[0]) >= 12) {
                output.append("PM ");
                if (Integer.parseInt(in.split(" ")[0]) != 12) {
                    output.append(Integer.parseInt(in.split(" ")[0]) - 12);
                } else {
                    output.append(Integer.parseInt(in.split(" ")[0]));
                }
            } else {
                output.append("AM ");
                if (Integer.parseInt(in.split(" ")[0]) == 0) {
                    output.append(Integer.parseInt(in.split(" ")[0]) + 12);
                } else {
                    output.append(Integer.parseInt(in.split(" ")[0]));
                }
                count++;
            }
            output.append(":").append(Integer.parseInt(in.split(" ")[1])).append("\n");
        }
        System.out.print(output.append(count));
    }
}
