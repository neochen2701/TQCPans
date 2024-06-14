import java.util.ArrayList;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class JPA101 {
    public static void calculateSumAvg(ArrayList<ArrayList<String>> inputs) {
        for (ArrayList<String> studentScores : inputs) {
            int count = 0;
            int sumScore = 0;
            for (int i = 1; i < studentScores.size(); i++) {
                sumScore += Integer.parseInt(studentScores.get(i));
                count++;
            }
            double avgScore = (double) sumScore / count;
            studentScores.add(String.valueOf(sumScore));
            studentScores.add(String.format("%.2f", avgScore));
        }
    }

    public static void main(String[] args) {
        ArrayList<ArrayList<String>> inputs = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            String inputStr = scanner.nextLine();
            if ("END".equals(inputStr)) { 
                break; 
            }
            String[] inputScores = inputStr.split(" ");
            ArrayList<String> studentScores = new ArrayList<>(Arrays.asList(inputScores));
            inputs.add(studentScores);
        }
        scanner.close();
        calculateSumAvg(inputs);

        Collections.sort(inputs, new Comparator<ArrayList<String>>() {
            public int compare(ArrayList<String> o1, ArrayList<String> o2) {
                int sum1 = Integer.parseInt(o1.get(o1.size() - 2));
                int sum2 = Integer.parseInt(o2.get(o2.size() - 2));
                return Integer.compare(sum2, sum1);
            }
        });

        for (ArrayList<String> studentScores : inputs) {
            System.out.print(String.join(" ", studentScores));
            System.out.printf("\n");
        }
    }
}
