import java.io.*;
import java.net.URISyntaxException;

public class JPA409 {
    public static void main(String[] arg) throws IOException, URISyntaxException {
        run();
    }

    public static void run() throws IOException, URISyntaxException {
        String readFilePath = Thread.currentThread().getContextClassLoader().getResource("read.txt").toURI().getPath();
        File file = new File(readFilePath);
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
        File writeFile = new File(readFilePath.replace("read.txt", "write.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter(writeFile));
        String text;
        int count = 0;
        while ((text = bufferedReader.readLine()) != null) {
            if (count != 0) {
                writer.newLine();
            }
            count++;
            for (char c : text.toCharArray()) {
                if (Character.isLowerCase(c)) {
                    if (c - 'a' >= 24) {
                        writer.write((c - 24));
                    } else {
                        writer.write((c + 2));
                    }
                } else {
                    writer.write(c);
                }
            }
            writer.flush();
        }
    }
}
