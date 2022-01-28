import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.util.Scanner;

class Bag {
	String receiptdate;
	int freight;
	int unitcost;
	double weight;

	Bag() {
	}
}
class Air extends Bag {

	Air() {
	}

	int deliveryhours;

	int computeFreight(int d, int c) {
		deliveryhours = d;
		int cost = c * deliveryhours;
		return cost;
	}
}

public class JPA06 {
	public static void main(String args[]) {
		try {
			String pathname = "read.txt";
			File f = new File(pathname);
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);

			String line = "";
			String[] date = new String[5];
			double[] weight = new double[5];
			int[] hour = new int[5];

			for (int i = 0; i < 5; i++) {
				line = br.readLine();
				String[] data = line.split(",");
				date[i] = data[0];
				weight[i] = Double.parseDouble(data[1]);
				hour[i] = Integer.parseInt(data[2]);
			}
			br.close();

			Scanner sc = new Scanner(System.in);
			int unitcost = sc.nextInt();
			sc.close();

			if (unitcost < 0) {
				System.out.print("error");
				return;
			}

			int totalcost = 0;
			Air Air = new Air();

			for (int h : hour)
				totalcost += Air.computeFreight(h, unitcost);
			System.out.print(totalcost);

		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}
