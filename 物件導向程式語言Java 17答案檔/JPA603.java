import java.util.Scanner;

abstract class Clerk {
	String name;
	double rate;
	double hours;
	double salary;

	Clerk(String n, double r, double h) {
		name = n;
		rate = r;
		hours = h;
	}

	abstract double salary();
}

class PartTime extends Clerk {
	PartTime(String n, double r, double h) {
		super(n, r, h);
	}

	public double salary() {
		return hours * rate;
	}
}

class FullTime extends Clerk {
	FullTime(String n, double r, double h) {
		super(n, r, h);
	}

	public double salary() {
		return 8 * rate + ((hours - 8) * rate * 0.9);
	}
}

public class JPA06 {
	public static void main(String argv[]) {
		String input = null;
		try {
			Scanner sc = new Scanner(System.in);
			input = sc.nextLine();
			sc.close();
		} catch (Exception ex) {
			System.out.print("error");
			return;
		}

		String data[] = input.split(" ");
		String type = data[0];
		String name = data[1];
		int pay = Integer.parseInt(data[2]);
		int hour = Integer.parseInt(data[3]);

		if (pay < 0 || hour < 0) {
			System.out.print("error");
			return;
		}

		if (type.equals("p")) {
			System.out.print("PartTime " + name + " " + (int) new PartTime(name, pay, hour).salary());
		} else if (type.equals("f")) {
			System.out.print("FullTime " + name + " " + (int) new FullTime(name, pay, hour).salary());
		} else {
			System.out.print("error");
			return;
		}
	}
}