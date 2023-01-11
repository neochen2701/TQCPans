import java.util.Scanner;

public class JPA102 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }
    public static void run(String input){
        float price = 23.34f;
        int inputCount = Integer.parseInt(input);
        System.out.print(String.format("%.2f", price * inputCount));
    }
}
