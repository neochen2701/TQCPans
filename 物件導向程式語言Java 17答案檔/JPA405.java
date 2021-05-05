import java.util.Random;
import java.util.Scanner;

public class JPA04 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// TO DO
		try {
			// TO DO
			int seed = sc.nextInt();
			sc.close();
			if(seed>100 || seed<1){
				System.out.print("error");
				System.exit(1);
			}
			Random rand = new Random(seed);
			int[] array = rand.ints(20, 1, 101).distinct().toArray();
			
			String output = "";
			for(int i = 0; i < 10; i++){
				output = output + array[i] + " ";
			}
			System.out.print(output.trim());			
			
		} catch (Exception ex) {
			System.out.print("error");
		}
	}
}