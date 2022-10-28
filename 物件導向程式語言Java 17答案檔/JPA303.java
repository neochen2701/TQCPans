import java.util.Scanner;
import java.util.Arrays;

public class JPA03 {
    public static int solve(String s){
        try{
            int x = Integer.parseInt(s);
            return x;
        }catch (NumberFormatException ex){
            return 0;
        }
    }

	public static void main(String[] args) {
		int[] num = new int[5];
		Scanner sc = new Scanner(System.in);
		for(int i = 0; i < 5; i++){
            String input = sc.nextLine();
            num[i] = solve(input);
        }
        compute(num);
	}

	public static void compute(int[] num) {
        for(int i = 0; i < 5; i++){
            for(int j = i+1; j < 5; j++){
                if(num[i] > num[j]){
                    int tmp = num[i];
                    num[i] = num[j];
                    num[j] = tmp;
                }
            }
        }
        for(int i = 0; i < 5; i++){
            System.out.print(num[i] + " ");
        }
	}
}
