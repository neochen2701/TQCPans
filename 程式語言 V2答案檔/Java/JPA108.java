import java.util.Objects;
import java.util.Scanner;

public class JPA108 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        System.out.println(String.format("%1$-10s",input));
        if (Objects.equals(input, "0")) {
            System.out.println(String.format("%1$-10s", "0.00"));
            System.out.print(String.format("%1$-10s","0.0000"));
        } else {
            Float radius = Float.parseFloat(input) / 2;
            System.out.println(String.format("%1$-10s",String.format("%.2f", radius)));
            System.out.print(String.format("%1$-10s",String.format("%.4f", radius * radius * 3.1415)));
        }

    }
}
