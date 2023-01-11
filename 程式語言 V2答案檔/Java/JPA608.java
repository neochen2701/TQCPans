import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class JPA608 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        int size = 10;
        String[] input = new String[size];
        for (int i = 0; i < size; i++) {
            input[i] = scan.nextLine();
        }
        run(input);
    }

    public static void run(String[] input) {
        int total = 0;
        List<Integer> numList = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            switch (Integer.parseInt(input[i])) {
                case 0:
                    // numList = new ArrayList<>(); 三振清空壘包
                    break;
                default:
                    int finalI = i;
                    int count = numList.size();
                    numList = numList.stream().map(num -> num += Integer.parseInt(input[finalI])).filter(num -> num < 4).collect(Collectors.toList());
                    total += (count - numList.size());
                    if (Integer.parseInt(input[i]) == 4) {
                        total++;
                    } else {
                        numList.add(Integer.parseInt(input[i]));
                    }
            }
        }
        System.out.print("score = " + total);
    }
}
