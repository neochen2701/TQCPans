import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.util.Scanner;

class Account {
	String name;
	double rate;
	double balance;

	Account(String s, double d) {
		name = s;
		rate = d;
	}

	void setRate(int d) {
		rate = d;
	}

	void deposit(int i) {
		balance += i;
	}

	void withdraw(int i) {
		balance -= i;
	}

	double balance() {
		return balance;
	}

	double addInterest(double rate) {
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

			String[] name = new String[5];
			String[] clas = new String[5];
			int[] number = new int[5];

			for (int i = 0; i < 5; i++) {
				line = br.readLine();
				String[] data = line.split(",");
				name[i] = data[0];
				number[i] = Integer.parseInt(data[1]);
				clas[i] = data[2];

			}

			Scanner sc = new Scanner(System.in);
			String input = sc.next();
			sc.close();

			double rate = Double.parseDouble(input);
			if (rate > 5 || (rate < 0)) {
				System.out.print("error");
				return;
			}
			Account acc = new Account("jack", rate);

			for (int i = 0; i < 5; i++) {
				if (clas[i].equals("d"))
					acc.deposit(number[i]);
				else
					acc.withdraw(number[i]);
			}

			double result = acc.addInterest(rate);

			if (result > (int) result)
				System.out.print(result);
			else
				System.out.print((int) result);

			br.close();

		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}