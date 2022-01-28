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

			String[] data = new String[13];
			int[] total = new int[13];
			String[] temp = null;
			String[] name = new String[13];

			for (int i = 0; i < 13; i++) {

				line = br.readLine();
				data[i] = line;
				temp = line.split(",");
				name[i] = temp[0];
				total[i] = Integer.parseInt(temp[3]) + Integer.parseInt(temp[4]) + Integer.parseInt(temp[5]);

			}
			br.close();

			Scanner sc = new Scanner(System.in);
			String input = sc.nextLine();
			sc.close();

			String[] judge = input.split(" ");

			int num = 0;
			String numkeep = "";
			for (int j = 0; j < 13; j++) {
				switch (judge[0]) {
				case ">":
					if (total[j] > Integer.parseInt(judge[1])) {
						num += 1;
						numkeep += name[j] + " " + total[j] + ",";
					}
					break;
				case "<":
					if (total[j] < Integer.parseInt(judge[1])) {
						num += 1;
						numkeep += name[j] + " " + total[j] + ",";
					}
					break;
				case ">=":
					if (total[j] >= Integer.parseInt(judge[1])) {
						num += 1;
						numkeep += name[j] + " " + total[j] + ",";
					}
					break;
				case "<=":
					if (total[j] <= Integer.parseInt(judge[1])) {
						num += 1;
						numkeep += name[j] + " " + total[j] + ",";
					}
					break;
				default:
					System.out.print("error");
					System.exit(0);
				}
			}

			System.out.println(num);
			String[] chk = numkeep.split(",");
			for (String result : chk) {
				System.out.println(result);
			}
		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}
