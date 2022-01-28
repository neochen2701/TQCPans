import java.io.File;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;

public class JPA05 {

	public static void main(String[] args) {

		try {
			String path = "read.txt";
			File f = new File(path);
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);

			String line = "";
			int[] total = new int[10];
			String[] id = new String[10];
			for (int i = 0; i < 10; i++) {
				line = br.readLine();
				id[i] = (line.split(","))[1];
				total[i] = Integer.parseInt((line.split(","))[2]) + Integer.parseInt((line.split(","))[3])
						+ Integer.parseInt((line.split(","))[4]);
			}
			br.close();

			Scanner sc = new Scanner(System.in);
			int input = sc.nextInt();
			sc.close();

			if (input > 10 || input < 1) {
				System.out.print("error");
				return;
			}

			int boytotal = 0;
			int boycount = 0;
			int girltotal = 0;
			int girlcount = 0;
			for (int i = 0; i < input; i++) {

				String com = id[i];
				if (com.substring(1, 2).equals("1")) {
					boytotal += total[i];
					boycount++;
				} else {
					girltotal += total[i];
					girlcount++;
				}
			}
			System.out.print("boys:" + (boytotal / (boycount * 3)) + "," + "girls:" + (girltotal / (girlcount * 3)));

		} catch (Exception ex) {
			System.out.print("error");
			return;
		}
	}
}
