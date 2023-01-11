import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

public class JPA610 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        String firstSize = scan.nextLine();
        String[] inputA = new String[toInt(firstSize.split(" ")[0])];
        for (int i = 0; i < toInt(firstSize.split(" ")[0]); i++) {
            inputA[i] = scan.nextLine();
        }

        String secondSize = scan.nextLine();
        String inputB;
        int[][] yRow = new int[toInt(secondSize.split(" ")[1])][toInt(secondSize.split(" ")[0])];

        for (int i = 0; i < toInt(secondSize.split(" ")[0]); i++) {
            inputB = scan.nextLine();
            for (int j = 0; j < toInt(secondSize.split(" ")[1]); j++) {
                yRow[j][i] = toInt(inputB.split(" ")[j]);
            }
        }

        if (!toInt(firstSize.split(" ")[1]).equals(toInt(secondSize.split(" ")[0]))) {
            System.out.print("error");
        } else {
            int[] xRow;
            int[][] result = new int[toInt(firstSize.split(" ")[0])][toInt(secondSize.split(" ")[1])];

            for (int i = 0; i < toInt(firstSize.split(" ")[0]); i++) {
                xRow = Arrays.stream(inputA[i].split(" ")).mapToInt(Integer::parseInt).toArray();
                for (int j = 0; j < toInt(secondSize.split(" ")[1]); j++) {
                    result[i][j] = countTotal(xRow, yRow[j]);
                }
            }
            for (int i = 0; i < result.length; i++) {
                System.out.print(Arrays.stream(result[i]).mapToObj(String::valueOf).collect(Collectors.joining(" ")));
                if (i != result.length - 1) {
                    System.out.println();
                }
            }
        }
    }

    private static Integer toInt(String input) {
        return Integer.parseInt(input);
    }

    private static Integer countTotal(int[] x, int[] y) {
        int total = 0;
        for (int i = 0; i < x.length; i++) {
            total += x[i] * y[i];
        }
        return total;
    }
}
