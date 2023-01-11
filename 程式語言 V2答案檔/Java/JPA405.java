import java.io.*;
import java.net.URISyntaxException;
import java.util.Scanner;

public class JPA405 {
    public static void main(String[] arg) throws IOException, URISyntaxException {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            String[] input = new String[3];
            input[0] = scan.nextLine();
            input[1] = scan.nextLine();
            input[2] = scan.nextLine();
            run(input);
        }
    }

    public static void run(String[] input) throws IOException, URISyntaxException {
        File file = new File(Thread.currentThread().getContextClassLoader().getResource("read.txt").toURI().getPath());
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
        for (String i : input) {
            String text = bufferedReader.readLine();
            for (int j = 0; j < Integer.parseInt(i); j++) {
                System.out.print(i);
            }
            System.out.print(text.substring(Integer.parseInt(i)));

            if (!i.equals(input[input.length - 1])) {
                System.out.println();
            }
        }
    }
}
