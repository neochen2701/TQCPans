import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.util.Scanner;

class Bag {
	String receiptdate;
	int freight;
	int unitcost;
	double weight;

	Bag(int u) {
        unitcost = u;
	}
}

class Air extends Bag{
    int deliveryhours;
    Air(int u){
        super(u);
    }
    int computeFreight(int d)
    {
        deliveryhours = d;
        freight =  unitcost * deliveryhours;
        return freight;
    }
}

public class JPD06 {
	public static void main(String args[]) {
		try {
        	String pathname = "read.txt";
			File f = new File(pathname);
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);

			String line = "";

            Scanner sc = new Scanner(System.in);
            int unit = sc.nextInt();
            if(unit < 0){
                System.out.print("error");
			    return;
            }

			int sum = 0;
            while((line = br.readLine()) != null){
                String data[] = line.split(",");
                int d = Integer.parseInt(data[1]);
                Air a = new Air(unit);
                sum += a.computeFreight(d);
            }
            br.close();

            System.out.print(sum);


		} catch (Exception e) {
			System.out.print("error");
			return;
		}
	}
}
