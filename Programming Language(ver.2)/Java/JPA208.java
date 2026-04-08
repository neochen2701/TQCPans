import java.util.Scanner;

public class JPA208 {
    public static void main(String[] arg) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) {
        int count;
        for (int i = 2; i < Integer.parseInt(input); i++) {
            count = 0;
            for(int j =2;j<=i;j++){
                if (i % j == 0) {
                    count++;
                }
            }
            if(count ==1){
                System.out.print(i + " ");
            }
        }
    }
}
