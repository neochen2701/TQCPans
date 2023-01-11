import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class JPA705 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        int line = 8;
        String[] input = new String[line];
        for (int i = 0; i < line; i++) {
            input[i] = scan.nextLine();
        }
        run(input);
    }

    public static void run(String[] input) {
        List<String> list = new ArrayList<>(List.of(input[0].split(" ")[0], input[1].split(" ")[0], input[2].split(" ")[0]));
        int total = 0;
        for(int i = 0;i<5;i++) {
            if(list.contains(input[i+3])){
                total += Integer.parseInt(input[list.indexOf(input[i+3])].split(" ")[1]);
            }
        }
        System.out.print(total);
    }
}
