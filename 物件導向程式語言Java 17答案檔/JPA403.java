import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class JPA04 {

	static int a = 0;

	public static void main(String[] args) throws Exception {

		String[] meetingDates = { "2018/12/01 14:00", "2018/12/02 15:00", "2018/12/03 10:30", "2018/12/03 15:30",
				"2018/12/04 15:00" };
		int[] meetingHours = { 1, 3, 4, 2, 5 };
		String strDate = null;
		Date com = null;

		try {
			Scanner sc = new Scanner(System.in);
			strDate = sc.nextLine();
			sc.close();

			SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd HH:mm");
			sdf.setLenient(false);
			com = sdf.parse(strDate);

			compare(meetingDates, meetingHours, com);

		} catch (Exception ex) {
			System.out.print("error");
			return;
		}
	}

	public static void compare(String[] meetingDates, int[] meetingHours, Date com) throws ParseException {

		SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd HH:mm");
		for (int i = 0; i < meetingDates.length; i++) {
			Date date1 = sdf.parse(meetingDates[i]);
			Calendar cal = Calendar.getInstance();
			cal.setTime(date1);
			cal.add(Calendar.HOUR_OF_DAY, meetingHours[i]);
			Date date2 = cal.getTime();

			if (com.after(date1) && com.before(date2)) {
				System.out.print("Has already reserved - " + meetingDates[i]);
				a++;
				break;
			} else {
				continue;
			}
		}
		if (a == 0) {
			System.out.print("Reservation completed - " + sdf.format(com));
		}
	}
}