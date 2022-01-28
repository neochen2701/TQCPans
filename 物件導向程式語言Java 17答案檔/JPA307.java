import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class JPA03 {

	public static void main(String[] argv) {

		List<String> data = new ArrayList<>();

		Scanner sc = new Scanner(System.in);
		while (true) {

			String input = sc.next();
			if (input.equals("999")) {
				break;
			}
			data.add(input);
		}
		sc.close();

		String[] arr = new String[data.size()];
		data.toArray(arr);

		System.out.print("before:");
		int len = arr.length;
		for (int a = 0; a < len; a++)
			if(a == len-1){
      			System.out.print(arr[a]);
   			}else{
      			System.out.print(arr[a] + " ");
   			}
		arr = compute(arr);
		System.out.print("\nafter:");
		for (int a = 0; a < len; a++)
			if(a == len-1){
      			System.out.print(arr[a]);
   			}else{
      			System.out.print(arr[a] + " ");
   			}
	}

	public static String[] compute(String[] s) {
		String[] temp = new String[s.length];
		int len = temp.length;
		int b = len - 1;
		for (int a = 0; a < len; a++) {
			temp[b] = s[a];
			b--;
		}
		return temp;
	}
}