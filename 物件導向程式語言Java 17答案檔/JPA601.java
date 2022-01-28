import java.util.Scanner;

class UnitCost {
	int cost = 0;
	public int getCost() {
		return cost;
	}
}

class Engine extends UnitCost {
	public Engine(int cc, int year) {
		if (cc == 1800)
			cost = 20000;
		else if (cc == 2000)
			cost = 25000;
		else {
			System.out.print("error");
			return;
		}

		if (year >= 2 && year < 5)
			cost *= 0.8;
		else if (year >= 5 && year <= 10)
			cost *= 0.7;
		else if (year > 10)
			cost *= 0.6;
	}
}

public class JPA06 {
	public static void main(String args[]) {
		String input = null;
		try {
			Scanner sc = new Scanner(System.in);
			input = sc.next();
			sc.close();

			String data[] = input.split(":");
			int cc = Integer.parseInt(data[0]);
			int year = Integer.parseInt(data[1]);
			System.out.print(new Engine(cc, year).getCost());
		} catch (Exception ex) {
			System.out.print("error");
			return;
		}
	}
}
