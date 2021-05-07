import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.util.Scanner;

class Account {
	String name;
	double rate = 1;
	double balance;
	boolean isCD = true;
	int yearration;

	Account(String n) {
		name = n;
	}

	Account(String n, int year) {
		name = n;
		if (year == 0) {
			rate = 1;
			isCD = false;
		} else if (year == 1)
			rate = 2;
		else if (year == 2)
			rate = 3;
		else if (year == 3)
			rate = 5;
		else {
			System.out.print("error");
			return;
		}
	}

	void setRate(int r) {
		rate = r;
	}

	void deposit(int d) {
		balance += d;
	}

	void withdraw(int w) {
		balance -= w;
	}

	double getBalance() {
		return balance;
	}

	double addInterest() {
		balance *= (rate / 100 + 1);
		return balance;
	}
}

class JPA06 {
	public static void main(String args[]) {
		try {
			String pathname = "read.txt";
			File f = new File(pathname);
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			String line = "";

			String[] name = new String[9];
			String[] clas = new String[9];
			int[] number = new int[9];

			for (int i = 0; i < 9; i++) {
				line = br.readLine();
				String[] data = line.split(",");
				name[i] = data[0];
				number[i] = Integer.parseInt(data[1]);
				clas[i] = data[2];

			}
			br.close();

			Scanner sc = new Scanner(System.in);
			String input = sc.nextLine();
			sc.close();
			String inputname = input.split(",")[0];
			int inputyear = Integer.parseInt(input.split(",")[1]);

			if (inputname.equals("jack") || inputname.equals("lily")) {
				if (inputyear > 3 || (inputyear < 0)) {
					System.out.print("error");
					System.exit(0);
				}
			} else {
				System.out.print("error");
				return;
			}

			Account accj = new Account("jack", inputyear);
			Account accl = new Account("lily", inputyear);

			double result = 0;
			String check = "";
			int ratecheck = 0;
			for (int i = 0; i < 9; i++) {
				if (name[i].equals("jack")) {
					if (clas[i].equals("d"))
						accj.deposit(number[i]);
					else if (clas[i].equals("w"))
						accj.withdraw(number[i]);
				}

				else if (inputname.equals("lily")) {
					if (clas[i].equals("d"))
						accl.deposit(number[i]);
					else if (clas[i].equals("w"))
						accl.withdraw(number[i]);
				}
			}

			if (inputname.equals("jack")) {
				result = accj.addInterest();
				ratecheck = (int) accj.rate;
				if (accj.isCD == true)
					check = "T";
				else
					check = "F";
			} else {
				result = accl.addInterest();
				ratecheck = (int) accl.rate;
				if (accl.isCD == true)
					check = "T";
				else
					check = "F";
			}

			if (result == (int) result)
				System.out.print(inputname + "," + check + "," + ratecheck + "%," + (int) result);
			else
				System.out.print(inputname + "," + check + "," + ratecheck + "%," + result);

		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}