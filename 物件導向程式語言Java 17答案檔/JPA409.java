import java.util.Scanner;
import java.time.LocalDate;
import java.time.Period;
import java.time.format.DateTimeFormatter;

public class JPA04 {

	public static void main(String[] args) {

		try {
			Scanner sc = new Scanner(System.in);
			String data1 = sc.next();
			String data2 = sc.next();
			sc.close();
			if (data1.compareTo(data2) > 0) {
				System.out.print("error");
				return;
			}

			DateTimeFormatter DTF = DateTimeFormatter.ofPattern("yyyyMMdd");
			LocalDate date1 = LocalDate.parse(data1, DTF);
			LocalDate date2 = LocalDate.parse(data2, DTF);
			Period p = Period.between(date1, date2);

			System.out.printf(p.getYears() + "y:" + p.getMonths() + "m:" + p.getDays() + "d");

		} catch (Exception ex) {
			System.out.print("error");
			return;
		}
	}
}