import java.util.Date;
import java.util.Locale;
import java.util.Scanner;
import java.text.SimpleDateFormat;

public class JPA04 {

	public static void main(String[] args) {

		try {
			Scanner sc = new Scanner(System.in);
			String data = sc.next();
			sc.close();

			String pattern = "yyyyMMdd";
			SimpleDateFormat sdf = new SimpleDateFormat(pattern);
			Date d = sdf.parse(data);

			pattern = "yyyy/MM/dd EEE";
			sdf = new SimpleDateFormat(pattern, Locale.US);
			System.out.print(sdf.format(d));

		} catch (Exception ex) {
			System.out.print("error");
			return;
		}
	}
}