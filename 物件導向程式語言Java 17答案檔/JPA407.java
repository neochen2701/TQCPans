import java.util.Calendar;
import java.util.Date;
import java.util.Random;
import java.util.Scanner;
import java.text.SimpleDateFormat;

public class JPA04 {

	public static void main(String[] args) {
		Random rand = new Random();
		int year = 0;
		try {
			Scanner sc = new Scanner(System.in);
			year = sc.nextInt();
			rand.setSeed(year);
			sc.close();
			if (year > 2018 || year < 2000) {
				System.out.print("error");
				System.exit(0);
			}

		} catch (Exception ex) {
			System.out.print("error");
		}
		System.out.print(year + ":");
		for (int i = 1; i <= 10; i++) {
			Date ans = randomDateBetweenMinAndMax(year, rand);
			SimpleDateFormat df = new SimpleDateFormat("M/d");
			System.out.print(String.valueOf(df.format(getWorkDay(ans)) + " "));
		}

	}

	public static Date randomDateBetweenMinAndMax(int year, Random rand) {
		Calendar calendar = Calendar.getInstance();

		calendar.set(year, 0, 1);
		calendar.getTime().getTime();

		calendar.set(Calendar.HOUR_OF_DAY, 0);

		long min = calendar.getTime().getTime();

		calendar.set(year, 11, 31);
		calendar.set(Calendar.HOUR_OF_DAY, 0);

		calendar.getTime().getTime();
		long max = calendar.getTime().getTime();

		double randomDate = rand.nextDouble() * (max - min) + min;

		calendar.setTimeInMillis(Math.round(randomDate));
		return calendar.getTime();
	}

	public static Date getWorkDay(Date startDate) {
		Calendar c1 = Calendar.getInstance();
		c1.setTime(startDate);
		for (int i = 0; i < 10; i++) {

			if (c1.get(Calendar.DAY_OF_WEEK) == Calendar.SATURDAY) {
				c1.add(Calendar.DATE, 2);
				continue;
			}

			else if (c1.get(Calendar.DAY_OF_WEEK) == Calendar.SUNDAY) {
				c1.add(Calendar.DATE, 1);
				continue;
			}
		}
		return c1.getTime();
	}
}