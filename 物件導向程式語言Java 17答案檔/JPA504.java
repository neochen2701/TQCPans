import java.io.File;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Scanner;

public class JPA05 {

	public static void main(String[] args) {

		String[] new_student = { "Sam", "1981/10/1", "A234567890" };
		String[] combine = new String[6];
		for (int i = 0; i < 3; i++) {
			combine[i] = new_student[i];

		}
		try {
			Scanner sc = new Scanner(System.in);
			String input = sc.nextLine();
			sc.close();

			String[] data = input.split(" ");

			for (int i = 0; i < 3; i++) {
				int chk = Integer.parseInt(data[i]);
				if (chk < 0 || chk > 100) {
					System.out.print("error");
					return;
				}
			}

			String result = "";
			for (int i = 3; i < 6; i++) {
				combine[i] = data[i - 3];
			}
			for (int i = 0; i < 5; i++) {
				result += combine[i] + ",";
			}

			result += combine[5];
			System.out.print(result);

			File f = new File("write.txt");
			FileWriter fw = new FileWriter(f, true);
			BufferedWriter bw = new BufferedWriter(fw);
			bw.write(result + "\r\n");
			bw.flush();
			bw.close();
			fw.close();

		} catch (Exception ex) {
			System.out.print("error");
			return;
		}
	}
}
