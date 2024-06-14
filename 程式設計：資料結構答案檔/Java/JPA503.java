import java.util.ArrayList;
import java.util.Scanner;

public class JPA503 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n1 = scanner.nextInt();
        int n2 = scanner.nextInt();
        
        ArrayList<Integer> A = new ArrayList<>(n1 + 1);
        ArrayList<Integer> B = new ArrayList<>(n2 + 1);
        
        A.add(0); 
        B.add(0); 
        
        for (int i = 0; i < n1; i++) {
            A.add(scanner.nextInt());
        }
        for (int j = 0; j < n2; j++) {
            B.add(scanner.nextInt());
        }
        
        ArrayList<Integer> DP = new ArrayList<>(n2 + 1);
        for (int i = 0; i <= n2; i++) {
            DP.add(0);
        }
        
        for (int i = 1; i <= n1; i++) {
            ArrayList<Integer> temp = new ArrayList<>(n2 + 1);
            for (int k = 0; k <= n2; k++) {
                temp.add(0);
            }
            for (int j = 1; j <= n2; j++) {
                if (!A.get(i).equals(B.get(j))) {
                    temp.set(j, Math.max(temp.get(j - 1), DP.get(j)));
                } else {
                    temp.set(j, DP.get(j - 1) + 1);
                }
            }
            DP = temp;
        }
        
        System.out.println(DP.get(n2));
    }
}
