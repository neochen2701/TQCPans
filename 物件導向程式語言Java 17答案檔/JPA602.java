import java.util.Scanner;

enum colors {
	RED, BLUE, WHITE
}

class Car {

	int cc, seat, door;
	colors color;

	Car(int cc, int seat, int colornum, int door) {
		this.cc = cc;
		this.seat = seat;
		this.door = door;
		switch (colornum) {
		case 1:
			color = colors.RED;
			break;
		case 2:
			color = colors.BLUE;
			break;
		case 3:
			color = colors.WHITE;
			break;
		default:
			System.out.print("error");
			System.exit(0);
		}
	}

	public String show() {
		String show = cc + "cc" + seat + color + door;
		return show;
	}
}

public class JPA06 {
	public static void main(String args[]) {
		String input = null;
		try {
			Scanner sc = new Scanner(System.in);
			input = sc.nextLine();
			sc.close();

			String data[] = input.split(" ");
			int cc = Integer.parseInt(data[0]);
			int seat = Integer.parseInt(data[1]);
			int color = Integer.parseInt(data[2]);
			int door = Integer.parseInt(data[3]);
			System.out.print(new Car(cc, seat, color, door).show());
		} catch (Exception ex) {
			System.out.print("error");
			return;
		}
	}
}
