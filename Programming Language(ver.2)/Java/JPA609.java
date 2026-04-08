import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class JPA609 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        run(scan.nextLine());
    }

    public static void run(String input) {
        List<Integer> monthList = new ArrayList<>(List.of(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31));
        int[] inputList = Arrays.stream(input.split(" ")).mapToInt(Integer::parseInt).toArray();
        if ((inputList[0] % 4 == 0 && inputList[0] % 100 != 0) || inputList[0] % 400 == 0) {
            monthList.set(1, 29);
        }

        if (inputList[1] < 1 || inputList[1] > 12 || inputList[2] < 1 || inputList[2] > monthList.get(inputList[1]-1)) {
            System.out.print("error");
        } else {
            int total = 0;
            for (int i = 0; i < inputList[1] - 1; i++) {
                total += monthList.get(i);
            }
            total += inputList[2];
            System.out.print(total);
        }

    }
}
