import java.io.File;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Scanner;

public class JPA05 {

	public static void main(String[] args) {

		String[] data = {
				"Life is difficult, life is unfair, life is challenging and sometimes painful. And life is so very good.",
				"There are frustrations, tragedies, disappointments, setbacks, heartbreaks, and absurdities. The simple joy of being outweighs them all.",
				"Life is good, because within its realm, anything is possible. Life is good, because no matter how far you fall, there is always a way to climb back up again.",
				"You can complain, fret and worry about all the problems in your life, but you'll be wasting your time. Or, you can choose to focus on why and how life is so good, and on what you can do to take that goodness and make it even better.",
				"Not only is life good, it's uniquely good for you in your very own way. The possibilities for expressing your purpose are limited only by your imagination.",
				"Remind yourself often of the great and wonderful value that you already, always have. Life is good, and in this moment that's bursting with possibilities, life is yours." };

		try {
			Scanner sc = new Scanner(System.in);
			String input = sc.nextLine();
			int num = Integer.parseInt(input);
			sc.close();

			if (input.equals("") || num < 1 || num > 6) {
				System.out.print("error");
				return;
			}

			File f = new File("write.txt");
			FileWriter fw = new FileWriter(f);
			BufferedWriter bw = new BufferedWriter(fw);

			for (int i = 0; i < num; i++) {
				bw.write(data[i] + "\r\n");

			}
			bw.flush();
			bw.close();
			fw.close();

		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}
