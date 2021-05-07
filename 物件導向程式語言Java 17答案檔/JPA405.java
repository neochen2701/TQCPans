import java.util.Scanner;

public class JPA04 {

	public static void main(String[] args) {

		try {

			String[] names = { "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra",
					"Scorpio", "Sagittarius", "Capricorn" };
			String[] dates = { "1/20", "2/19", "3/21", "4/20", "5/21", "6/21", "7/23", "8/23", "9/23", "10/23", "11/22",
					"12/22" };

			Scanner sc = new Scanner(System.in);
			String inputdata = sc.next();
			sc.close();

			String inputdate = inputdata.substring(4);

			int monthday = Integer.parseInt(inputdate);
			int month = monthday / 100;
			int day = monthday % 100;

			if (month > 12 || month < 1) {
				System.out.print("error");
				System.exit(0);
			} else if (day > 31 || day < 1) {
				System.out.print("error");
				System.exit(0);
			}

			String sign = "";
			switch (month) {
			case 1:
				sign = day < 21 ? "Capricorn" : "Aquarius";
				break;
			case 2:
				sign = day < 20 ? "Aquarius" : "Pisces";
				break;
			case 3:
				sign = day < 21 ? "Pisces" : "Aries";
				break;
			case 4:
				sign = day < 21 ? "Aries" : "Taurus";
				break;
			case 5:
				sign = day < 22 ? "Taurus" : "Gemini";
				break;
			case 6:
				sign = day < 22 ? "Gemini" : "Cancer";
				break;
			case 7:
				sign = day < 23 ? "Cancer" : "Leo";
				break;
			case 8:
				sign = day < 24 ? "Leo" : "Virgo";
				break;
			case 9:
				sign = day < 24 ? "Virgo" : "Libra";
				break;
			case 10:
				sign = day < 24 ? "Libra" : "Scorpio";
				break;
			case 11:
				sign = day < 23 ? "Scorpio" : "Sagittarius";
				break;
			case 12:
				sign = day < 22 ? "Sagittarius" : "Capricorn";
				break;
			}
			System.out.print(sign);

		} catch (Exception e) {
			System.out.print("error");
			System.exit(0);
		}

	}

}