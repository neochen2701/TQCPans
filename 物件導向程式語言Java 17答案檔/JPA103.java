import java.util.Scanner;  // Import the Scanner class

public class JPA01 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    try{
      double num = sc.nextDouble();
      System.out.printf("%.4f\n", Math.PI * num * num);
    }catch(Exception e){
      System.out.println("0.0000");
    }
    return;
  }
}