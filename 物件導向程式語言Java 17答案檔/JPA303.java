import java.util.Scanner;
import java.util.Arrays;

public class JPA03 {

	public static void main(String[] args) {

		int[] numbers = new int[5];
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			try {
				numbers[i] = sc.nextInt();
			} catch (Exception e) {
				numbers[i] = 0;
				sc.next();
			}
		}
		sc.close();

		compute(numbers);
	}

public static void compute(int[] numbers) {
  Arrays.sort(numbers);
  for (int i = 0 ; i < numbers.length; i++){
   if(i == 4){
      System.out.print(numbers[i]);
   }else{
      System.out.print(numbers[i] + " ");
   }
    
   
  }

 }
}
