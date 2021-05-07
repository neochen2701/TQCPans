import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class JPA04 {

	static int sum = 0;

	public static void main(String[] args) {
		try {
			Scanner sc = new Scanner(System.in);
			String inputdata1 = sc.next();
			if (isdate(inputdata1) == false) {
				System.out.print("error");
				System.exit(0);
			}

			SimpleDateFormat sdf = new SimpleDateFormat("yyyyMMdd");
			Date date1 = sdf.parse(inputdata1);

			String inputdata2 = sc.next();
			if (isdate(inputdata2) == false) {
				System.out.print("error");
				return;
			}
			sc.close();

			Date date2 = sdf.parse(inputdata2);

			int days = Math.abs((int) ((date2.getTime() - date1.getTime()) / (1000 * 3600 * 24)));

			System.out.print(days);

		} catch (Exception ex) {
			System.out.print("error");
			return;
		}
	}

	public static boolean isdate(String date) {
		String rexp = "^((\\d{2}(([02468][048])|([13579][26]))[\\-\\/\\s]?((((0?[13578])|(1[02]))[\\-\\/\\s]?((0?[1-9])|([1-2][0-9])|(3[01])))|(((0?[469])|(11))[\\-\\/\\s]?((0?[1-9])|([1-2][0-9])|(30)))|(0?2[\\-\\/\\s]?((0?[1-9])|([1-2][0-9])))))|(\\d{2}(([02468][1235679])|([13579][01345789]))[\\-\\/\\s]?((((0?[13578])|(1[02]))[\\-\\/\\s]?((0?[1-9])|([1-2][0-9])|(3[01])))|(((0?[469])|(11))[\\-\\/\\s]?((0?[1-9])|([1-2][0-9])|(30)))|(0?2[\\-\\/\\s]?((0?[1-9])|(1[0-9])|(2[0-8]))))))";
		Pattern pat = Pattern.compile(rexp);
		Matcher mat = pat.matcher(date);
		boolean dateType = mat.matches();
		return dateType;
	}
}