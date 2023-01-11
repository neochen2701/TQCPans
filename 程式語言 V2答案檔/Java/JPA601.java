import java.util.Scanner;

public class JPA601 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        String[] input = new String[2];
        input[0] = scan.nextLine();
        input[1] = scan.nextLine();
        run(input);
    }

    public static void run(String[] input) {
        char select = input[0].charAt(Integer.parseInt(input[1]));
        System.out.println("The letter that was selected is: " + (Character.isUpperCase(select) ? Character.toLowerCase(select) : Character.toUpperCase(select)));
        int count = 0;
        for (String in : input[0].split("")) {
            if (Integer.parseInt(input[1]) == count) {
                System.out.print(Character.isUpperCase(in.charAt(0)) ? Character.toLowerCase(in.charAt(0)) : Character.toUpperCase(in.charAt(0)));
            } else {
                System.out.print(in);
            }
            count++;
        }

    }
}
