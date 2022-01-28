import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.Scanner;

class Staff {
	String name = "";
	int leavehours = 0;
	boolean isleader = false;

	Staff(String n, int h) {
		name = n;
		leavehours = h;
	}
}

interface ILeave {
	public abstract void takeLeave(int h);
}

class Manager extends Staff implements ILeave {
	Manager(String n, int h) {
		super(n, h);
		isleader = true;
	}

	public void takeLeave(int h) {
		leavehours += h;
	}
}

class Worker extends Staff implements ILeave {
	Worker(String n, int h) {
		super(n, h);
	}

	public void takeLeave(int h) {
		leavehours += h;
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
			String[] name = new String[29];
			String[] type = new String[29];
			String[] dates = new String[29];
			int[] hours = new int[29];

			for (int i = 0; i < 29; i++) {
				line = br.readLine();
				String[] data = line.split(",");
				name[i] = data[0];
				type[i] = data[1];
				dates[i] = data[2];
				hours[i] = Integer.parseInt(data[3]);
			}
			br.close();

			Scanner sc = new Scanner(System.in);
			int inputhour = sc.nextInt();
			sc.close();

			if (inputhour < 0) {
				System.out.print("error");
				return;
			}

			ArrayList<Integer> mgers = new ArrayList<Integer>();
			ArrayList<Integer> wors = new ArrayList<Integer>();
			int mgerhour = 0, worhour = 0;

			for (int i = 0; i < 29; i++) {
				if (hours[i] >= inputhour) {
					if (type[i].equals("m")) {
						mgers.add(hours[i]);
					} else {
						wors.add(hours[i]);
					}
				}
			}

			for (int m : mgers) {
				mgerhour += m;
			}
			for (int w : wors) {
				worhour += w;
			}
			System.out.print("Manager" + mgerhour + "hr/Worker" + worhour + "hr");

		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}