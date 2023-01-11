import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;
import java.util.function.Function;
import java.util.stream.Collectors;

public class JPA404 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        Map<String, Long> countMap = Arrays.stream(input.split("")).collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
        Map.Entry<String, Long> maxEntry = countMap.entrySet().stream().max(Map.Entry.comparingByValue()).get();
        System.out.print(maxEntry.getKey() + "\n" + maxEntry.getValue());
    }
}
