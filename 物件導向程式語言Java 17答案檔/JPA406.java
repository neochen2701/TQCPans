import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class JPA04 {

    public static void main(String[] args) {
	    Scanner scanner = new Scanner(System.in);
        int n;
        try {
            n = scanner.nextInt();
            scanner.close();

            if (n >= 1 && n <= 100){
                Random random = new Random(n);
                ArrayList<Integer> list = new ArrayList<Integer>();
                
                while (list.size() < 10){
                    int r = random.nextInt(100) + 1;
                    if (list.contains(r)) continue;
                    list.add(r);
                }

                for (int item: list) {
                    System.out.print(item + " ");
                }
            } else {
                System.out.println("error");
            }
        } catch (Exception ex){
            System.out.println("error");
        }
    }
}