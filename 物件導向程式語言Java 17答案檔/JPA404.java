import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class JPA04 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String strDate = sc.next();
		sc.close();

		SimpleDateFormat sdf = new SimpleDateFormat("yyyyMMdd");
		sdf.setLenient(false);
		Date date = null;
		try {
			date = sdf.parse(strDate);
			sdf = new SimpleDateFormat("yyyy/MM/dd");
			strDate = sdf.format(date);
		} catch (Exception e) {
			System.out.print("error");
			return;
		}

		Calendar cal = Calendar.getInstance();
		cal.setTime(date);
		int w = cal.get(Calendar.DAY_OF_WEEK) - 1;
		sdf = new SimpleDateFormat("yyyy/MM/dd");
		if (w == 0) {
			cal.add(Calendar.DAY_OF_YEAR, -6);
			Date dt1 = cal.getTime();
			String reStr = sdf.format(dt1);
			System.out.print(reStr + "-" + strDate);

		} else {
			cal.add(Calendar.DAY_OF_YEAR, -6 - w);
			Date dtstr = cal.getTime();
			cal.add(Calendar.DAY_OF_YEAR, 6);
			Date dtend = cal.getTime();
			sdf = new SimpleDateFormat("yyyy/MM/dd");
			String reStr = sdf.format(dtstr);
			String reend = sdf.format(dtend);
			System.out.print(reStr + "-" + reend);
		}
	}
}
