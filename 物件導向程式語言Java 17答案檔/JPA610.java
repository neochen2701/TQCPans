import java.util.Scanner;

class Part {
	int cost;

	Part() {
		cost = 0;
	}

	public int getcost() {
		return cost;
	}
}

class LCD extends Part {
	LCD(int size) {
		if (size == 10)
			cost = 1500;
		else if (size == 15)
			cost = 2500;
		else if (size == 17)
			cost = 3500;
	}
}

class CPU extends Part {
	CPU(double speed) {
		if (speed == 1.66)
			cost = 7000;
		else if (speed == 2.2)
			cost = 8500;
		else if (speed == 2.4)
			cost = 13000;
	}
}

class hd extends Part {
	hd(int s) {
		if (s == 256)
			cost = 1800;
		else if (s == 512)
			cost = 2500;
	}
}

class Notebook {
	double cost;
	LCD l;
	CPU c;
	hd h;

	Notebook() {
		l = new LCD(10);
		c = new CPU(1.66);
		h = new hd(256);
		cost = l.getcost() + c.getcost() + h.getcost();
	}

	Notebook(int i, double d, int s) {
		l = new LCD(i);
		c = new CPU(d);
		h = new hd(s);
		cost = l.getcost() + c.getcost() + h.getcost();
	}

	double profit;

	public double getCost() {
		return cost;
	}

	public double getPrice(double pro) {
		return cost * pro;
	}
}

public class JPA06 {
	public static void main(String args[]) {
		int number = 0;
		double profit = 0;
		int length = 0;
		int l = 0;
		double c = 0;
		int h = 0;
		try {
			Scanner sc = new Scanner(System.in);
			String input = sc.nextLine();
			sc.close();
			String[] data = input.split(" ");
			length = data.length;
			if (length == 2) {
				number = Integer.parseInt(data[0]);
				profit = Double.parseDouble(data[1]);
			} else if (length == 5) {
				number = Integer.parseInt(data[0]);
				profit = Double.parseDouble(data[1]);
				l = Integer.parseInt(data[2]);
				c = Double.parseDouble(data[3]);
				h = Integer.parseInt(data[4]);
				;
			}
		} catch (Exception e) {
			System.out.print("error");
			return;
		}

		Notebook Notebook;
		if (length == 2) {
			Notebook = new Notebook();
			double cost = Notebook.getCost() * number;
			double price = Notebook.getPrice(profit) * number;
			System.out.print("NB:" + number + ",Cost:" + Math.round(cost) + ",Total:" + Math.round(price));
		} else if (length == 5) {
			Notebook = new Notebook(l, c, h);
			double cost = Notebook.getCost() * number;
			double price = Notebook.getPrice(profit) * number;
			System.out.print("NB:" + number + ",Cost:" + Math.round(cost) + ",Total:" + Math.round(price));
		} else {
			System.out.print("error");
			return;
		}
	}
}