import java.io.*;
import java.net.URISyntaxException;
import java.util.Scanner;

public class JPA410 {
    public static void main(String[] arg) throws IOException, URISyntaxException {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            run(scan.nextLine());
        }
    }

    public static void run(String input) throws IOException, URISyntaxException {
        String readFilePath = Thread.currentThread().getContextClassLoader().getResource("read.txt").toURI().getPath();
        File file = new File(readFilePath);
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
        File writeFile = new File(readFilePath.replace("read.txt", "write.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter(writeFile));
        String text;
        StringBuilder output = new StringBuilder();
        int count = 0;
        for (int i = 0; i < Integer.parseInt(input); i++) {
            if ((text = bufferedReader.readLine()) == null) {
                break;
            }
            if (count != 0) {
                output.append("\n");
            }
            count++;
            String[] splitText = text.split(" ");
            if (splitText.length > 0 && !text.equals("")) {
                for (String s : splitText) {
                    output.append(s.replaceFirst(String.valueOf(s.charAt(0)), String.valueOf(Character.toUpperCase(s.charAt(0))))).append(" ");
                }
                output.deleteCharAt(output.lastIndexOf(" "));
            }
        }
        System.out.print(output);
        writer.write(output.toString());
        writer.flush();
    }
}
