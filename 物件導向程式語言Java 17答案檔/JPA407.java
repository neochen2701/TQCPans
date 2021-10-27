import java.util.Calendar;
import java.util.Date;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.text.SimpleDateFormat;

public class JPA04 {

	public static void main(String[] args) {
		Random rand = new Random();
		int year = 0;
        List<String> result = new ArrayList<>();

		try {
			Scanner sc = new Scanner(System.in);
			year = sc.nextInt();
			rand.setSeed(year);
			sc.close();
			if (year > 2018 || year < 2000) {
				throw new Exception();
			}

            System.out.print(year + ":");

            while (result.size() < 10) {
                Date ans = randomDateBetweenMinAndMax(year, rand);
                SimpleDateFormat df = new SimpleDateFormat("M/d");
                String dayString = String.valueOf(df.format(ans));
                if (validWorkDay(ans) && !result.contains(dayString))
                    result.add(dayString);
            }

            result.forEach(x->System.out.print(x + " "));
		} catch (Exception ex) {
			System.out.print("error");
		}
	}

	public static Date randomDateBetweenMinAndMax(int year, Random rand) {
		Calendar calendar = Calendar.getInstance();

		calendar.set(year, 0, 1);
		calendar.set(Calendar.HOUR_OF_DAY, 0);
        calendar.set(Calendar.MINUTE,0);
        calendar.set(Calendar.SECOND,0);
		long min = calendar.getTime().getTime();

		calendar.set(year, 11, 31);
		calendar.set(Calendar.HOUR_OF_DAY, 23);
        calendar.set(Calendar.MINUTE,59);
        calendar.set(Calendar.SECOND,59);
		long max = calendar.getTime().getTime();

		double randomDate = rand.nextDouble() * (max - min) + min;

		calendar.setTimeInMillis(Math.round(randomDate));
		return calendar.getTime();
	}

    public static boolean validWorkDay(Date date) {
        Calendar c1 = Calendar.getInstance();
		c1.setTime(date);
        return !(c1.get(Calendar.DAY_OF_WEEK) == Calendar.SATURDAY || c1.get(Calendar.DAY_OF_WEEK) == Calendar.SUNDAY);
    }
}