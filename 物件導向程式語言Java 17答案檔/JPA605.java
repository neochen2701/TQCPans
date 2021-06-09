import java.util.Calendar;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.util.Scanner;

interface Ilogin {
	public void login(String n, String d, String t);
}

interface Ilogout {

	public void logout();
}

class Staff {
	String name;
	Date logintime, logouttime, workdate, worktime;
}

class Manager extends Staff implements Ilogin, Ilogout {

	Manager(String n, String d, String t) {
		SimpleDateFormat dateformat = new SimpleDateFormat("yyyy/MM/dd");
		SimpleDateFormat timeformat = new SimpleDateFormat("HH:mm:ss");
		super.name = n;
		Date wd;
		Date wt;
		try {
			wd = dateformat.parse(d);
			wt = timeformat.parse(t);
			super.workdate = wd;
			super.worktime = wt;
		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}

	public void login(String n, String d, String t) {

		SimpleDateFormat loginformat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		super.name = n;
		Date logintime;
		try {
			logintime = loginformat.parse((d + " " + t));
			super.logintime = logintime;
			System.out.print(n + " Login " + loginformat.format(super.logintime));
		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}

	public void logout() {
		try {
			super.logouttime = logintime;

			SimpleDateFormat dtformat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
			Calendar calendar = Calendar.getInstance();
			calendar.setTime(logouttime);
			calendar.add(Calendar.SECOND, 2);
			logouttime = calendar.getTime();
			System.out.print(",Logout " + dtformat.format(super.logouttime));
		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}

public class JPA06 {

	public static void main(String[] args) {
		Scanner sc = new java.util.Scanner(System.in);
		String n, d, t;

		try {
			String typein = sc.nextLine();
			sc.close();

			String[] getvalues = typein.split(" ");
			n = getvalues[0];
			d = getvalues[1];
			t = getvalues[2];

			Manager m = new Manager(n, d, t);

			m.login(n, d, t);
			Thread.sleep(2000);
			m.logout();

		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}
