import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class JPA304 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        scanner.nextLine();
        
        ArrayList<String> fabrics = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String s = scanner.nextLine();
            fabrics.add(s);
        }
        
        Collections.sort(fabrics);
        
        int ans = 0;
        for (String s1 : fabrics) {
            int len = s1.length();
            for (int i = 1; i <= len / 2; i++) {
                if (s1.substring(0, i).equals(s1.substring(len - i))) {
                    String subStr = s1.substring(i, len - i);
                    if (Collections.binarySearch(fabrics, subStr) >= 0) {
                        ans++;
                    }
                }
            }
        }
        
        System.out.println(ans);
        
        scanner.close();
    }
}
