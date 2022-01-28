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

			String[] data = new String[11];
			for (int i = 0; i < 10; i++) {
				line = br.readLine();
				data[i] = line;
			}
			br.close();

			Scanner sc = new Scanner(System.in);
			int num = sc.nextInt();

			if (num < 1 || num > 10) {
				System.out.print("error");
				return;
			} else {
				System.out.print(num + ":" + data[num - 1]);
			}
			sc.close();

		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}
