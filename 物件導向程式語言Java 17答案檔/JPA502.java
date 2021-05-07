import java.io.File;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class JPA05 {

	public static void main(String[] args) {

		try {
			Scanner sc = new Scanner(System.in);
			String input = sc.nextLine();
			sc.close();

			if (input.equals("")) {
				System.out.print("error");
				System.exit(0);
			}

			File f = new File("write.txt");
			FileWriter fw = new FileWriter(f);
			BufferedWriter bw = new BufferedWriter(fw);
			bw.write(input);
			bw.flush();
			bw.close();
			fw.close();

			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			String line = br.readLine();
			print(line);

			br.close();

		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}

	public static void print(String line) {
		System.out.print("write:" + line);
	}

}
