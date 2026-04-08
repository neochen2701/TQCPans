import java.util.Scanner;

public class JPA507 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        String[] input = new String[4];
        input[0] = scan.nextLine();
        input[1] = scan.nextLine();
        input[2] = scan.nextLine();
        input[3] = scan.nextLine();
        run(input);
    }

    public static void run(String[] input) {
        int[] result = new int[6];
        for (int i = 0; i < 4; i++) {
            if (input[0].charAt(i) == (input[1].charAt(i))) {
                result[0]++;
            }
            if (input[0].contains(String.valueOf(input[1].charAt(i)))) {
                result[1]++;
            }
            if (input[0].charAt(i) == (input[2].charAt(i))) {
                result[2]++;
            }
            if (input[0].contains(String.valueOf(input[2].charAt(i)))) {
                result[3]++;
            }
            if (input[0].charAt(i) == (input[3].charAt(i))) {
                result[4]++;
            }
            if (input[0].contains(String.valueOf(input[3].charAt(i)))) {
                result[5]++;
            }
        }
        System.out.print(result[0] + "A" + (result[1] - result[0]) + "B" + "\n" +
                result[2] + "A" + (result[3] - result[2]) + "B" + "\n" +
                result[4] + "A" + (result[5] - result[4]) + "B");

    }
}
