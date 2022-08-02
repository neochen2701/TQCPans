import java.util.Scanner;

public class JPA02 {
    public static boolean isodd(int x){
        if(x%2 == 0)
            return false;
        else
            return true;
    }
	public static void main(String[] args) {
        int x;
		try {
			Scanner sc = new Scanner(System.in);
			String s = sc.nextLine();
            x = Integer.parseInt(s);
		} catch (Exception e) {
			System.out.println("error");
            return;
		}
        if(isodd(x))
            System.out.print(x + " is an odd number.");
        else
            System.out.print(x + " is an even number.");
        return;
	}
}