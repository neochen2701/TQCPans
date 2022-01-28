import java.util.Scanner;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

abstract class Clerk {
	String name;
	double rate;
	double hours;
	double salary;
	boolean isManager;

	Clerk(String n, double r, double h, boolean i) {
		name = n;
		rate = r;
		hours = h;
		isManager = i;
	}

	abstract double salary();
}

class PartTime extends Clerk {
	PartTime(String n, double r, double h, boolean i) {
		super(n, r, h, i);
	}

	public double salary() {
		return hours * rate;
	}
}

class FullTime extends Clerk {
	FullTime(String n, double r, double h, boolean i) {
		super(n, r, h, i);
	}

	public double salary() {
		if (isManager == true) {
			return (8 * rate + ((hours - 8) * rate * 0.9)) * 1.2;
		} else {
			return 8 * rate + ((hours - 8) * rate * 0.9);
		}
	}
}

public class JPA06 {
	public static void main(String argv[]) {

		try {
			String pathname = "read.txt";
			File f = new File(pathname);
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			String line = "";

			String[] name = new String[7];
			String[] type = new String[7];
			int[] hour = new int[7];

			for (int i = 0; i < 7; i++) {
				line = br.readLine();
				String[] data = line.split(",");
				type[i] = data[0];
				name[i] = data[1];
				hour[i] = Integer.parseInt(data[2]);
			}
			br.close();

			Scanner sc = new Scanner(System.in);
			String pay = sc.nextLine();
			String[] payarr = pay.split(" ");
			if (payarr.length > 2) {
				System.out.print("error");
				return;
			}
			sc.close();

			int ppay = Integer.parseInt(payarr[0]);
			int fpay = Integer.parseInt(payarr[1]);
			int total = 0;
			double salary = 0;

			for (int i = 0; i < 7; i++) {
				if (type[i].equals("p")) {
					salary = new PartTime(name[i], ppay, hour[i], false).salary();
					total += salary;
				} else if (type[i].equals("f")) {
					salary = new FullTime(name[i], fpay, hour[i], false).salary();
					total += salary;
				} else {
					salary = new FullTime(name[i], fpay, hour[i], true).salary();
					total += salary;
				}
			}
			System.out.print("PartTime:" + ppay + ",FullTime:" + fpay + ",Salary:" + total);

		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}