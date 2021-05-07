import java.io.File;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class JPA05 {

	public static void main(String[] args) {

		try {
			int num = 22;
			String path = "read.txt";
			File f = new File(path);
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);

			String line = "";
			String[] data = new String[num];
			String[] id = new String[num];
			for (int i = 0; i < num; i++) {
				line = br.readLine();
				data[i] = line;
				id[i] = (line.split(",")[0]);
			}
			br.close();

			Scanner sc = new Scanner(System.in);
			int input = sc.nextInt();
			sc.close();
			if (input > num)
				input = num;
			if (input < 5) {
				System.out.print("error");
				return;
			}

			File w = new File("write.txt");
			FileWriter fw = new FileWriter(w);
			BufferedWriter bw = new BufferedWriter(fw);
			for (int i = 0; i < input; i++) {
				for (int j = 0; j < num; j++) {
					if (data[j].split(",")[0].equals(String.valueOf(i + 1))) {
						bw.write(data[j] + "\r\n");
					}
				}
			}
			bw.flush();
			bw.close();
			fw.close();
		} catch (Exception ex) {
			System.out.print("error");
			return;
		}
	}
}
