import java.util.Scanner;

public class JPA607 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        run(scan.nextLine());
    }

    public static void run(String input) {
        String[] inputList = input.split(" ");
        if (inputList[0].charAt(0) > inputList[1].charAt(0)) {
            System.out.print(inputList[0] + " > " + inputList[1]);
        } else if (inputList[0].charAt(0) < inputList[1].charAt(0)) {
            System.out.print(inputList[0] + " < " + inputList[1]);
        } else if (inputList[0].equals(inputList[1])) {
            System.out.print(inputList[0] + " = " + inputList[1]);
        } else {
            int firstNum = Integer.parseInt(inputList[0].replaceAll(String.valueOf(inputList[0].charAt(0)), ""));
            int secondNum = Integer.parseInt(inputList[1].replaceAll(String.valueOf(inputList[0].charAt(0)), ""));
            if (firstNum == secondNum) {
                System.out.print(inputList[0] + " = " + inputList[1]);
            } else {
                System.out.print(inputList[0] + " " + (firstNum > secondNum ? ">" : "<") + " " + inputList[1]);
            }
        }
    }
}
