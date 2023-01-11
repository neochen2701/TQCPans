import java.util.Scanner;

public class JPA510 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        String size = scan.nextLine();
        int x = Integer.parseInt(size.split(" ")[0]);
        String[] input = new String[x + 1];
        for (int i = 1; i <= x; i++) {
            input[i] = scan.nextLine();
        }
        input[0] = size;
        run(input);
    }

    public static void run(String[] input) {
        StringBuilder output = new StringBuilder();
        for (int i = 1; i < input.length; i++) {
            input[i] = input[i].replaceAll(" ", "");
        }
        int x = Integer.parseInt(input[0].split(" ")[0]);
        int y = Integer.parseInt(input[0].split(" ")[1]);
        for (int i = 1; i <= x; i++) {
            for (int j = 0; j < y; j++) {
                if (i == 1 || j == 0 || i == x || j == y - 1) { // 邊
                    output.append(String.valueOf(input[i].charAt(j)).equals("1") ? "*" : " ");
                } else {
                    if ((String.valueOf(input[i - 1].charAt(j)).equals("0") ||
                            String.valueOf(input[i + 1].charAt(j)).equals("0") ||
                            String.valueOf(input[i].charAt(j - 1)).equals("0") ||
                            String.valueOf(input[i].charAt(j + 1)).equals("0")) &&
                            String.valueOf(input[i].charAt(j)).equals("1")) {
                        output.append("*");
                    } else {
                        output.append(" ");
                    }
                }
            }
            output.append("\n");
        }
        System.out.print(output.deleteCharAt(output.lastIndexOf("\n")));
    }
}
