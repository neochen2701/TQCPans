import java.io.File;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;

public class JPA05 {

	public static void main(String[] args) {

		try {
			String path = "read.txt";
			File f = new File(path);
			FileReader fw = new FileReader(f);
			BufferedReader br = new BufferedReader(fw);

			String line = "";
			for (int i = 0; i < 1; i++) {
				line += br.readLine();
			}
			br.close();

			Scanner sc = new Scanner(System.in);
			String chk = sc.nextLine();
			int index = (line.split(chk)).length - 1;
			System.out.print(index);
			sc.close();

		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}
