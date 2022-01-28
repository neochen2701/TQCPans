import java.io.File;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class JPA05 {

	public static void main(String[] args) {

		try {
			String path = "read.txt";
			File f = new File(path);
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);

			String line = "";
			String[] data = new String[13];
			for (int i = 0; i < 13; i++) {
				line = br.readLine();
				data[i] = line;

			}
			br.close();

			Scanner sc = new Scanner(System.in);
			int judge = sc.nextInt();
			sc.close();

			if (judge < 1 || judge > 13) {
				System.out.print("error");
				return;
			}
			data = delete(data, judge - 1);

			String file = "write.txt";
			FileWriter fw = new FileWriter(file);
			BufferedWriter bw = new BufferedWriter(fw);

			for (int i = 0; i < data.length; i++) {
				bw.write(data[i] + "\r\n");
			}
			bw.flush();
			bw.close();

		} catch (Exception e) {
			System.out.print("error");
			return;
		}

	}

	public static String[] delete(String[] n, int index) {
		String delete = n[index].split(",")[1];

		int j = 0;
		String[] b = new String[n.length - 1];
		for (int i = 0; i < n.length; i++) {
			if (i == index)
				continue;
			b[j++] = n[i];
		}
		System.out.print("Delete:" + (index + 1) + " " + delete);
		return b;
	}
}
