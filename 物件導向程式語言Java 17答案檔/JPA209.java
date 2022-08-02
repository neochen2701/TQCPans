import java.util.Scanner;

public class JPA02 {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String xs, ys;
        double x, y;
        String dimen;
        try{
            xs = sc.nextLine();
            ys = sc.nextLine();
            x = Double.parseDouble(xs);
            y = Double.parseDouble(ys);
        }catch(Exception e){
            System.out.print("error");
            return;
        }
        
        if(x == 0 && y == 0)
            dimen = "origin";
        else if(y == 0)
            dimen = "X";
        else if (x == 0)
            dimen = "Y";
        else if(x > 0 && y > 0)
            dimen = "1";
        else if(x < 0 && y > 0)
            dimen = "2";
        else if(x < 0 && y < 0)
            dimen = "3";
        else
            dimen = "4";

        System.out.printf("(%s,%s) %s", xs, ys, dimen);
	}
}