import java.util.Scanner;

public class JPA203 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        switch (input) {
            case "1":
                System.out.print("one");
                break;
            case "2":
                System.out.print("two");
                break;
            case "3":
                System.out.print("three");
                break;
            case "4":
                System.out.print("four");
                break;
            default:
                System.out.print("error");
        }
    }
}
