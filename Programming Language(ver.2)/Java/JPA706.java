import java.io.*;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class JPA706 {
    public static void main(String[] arg) throws URISyntaxException, IOException {
        Scanner scan = new Scanner(System.in);
        int line = 4;
        String[] input = new String[line];
        for (int i = 0; i < line; i++) {
            input[i] = scan.nextLine();
        }
        run(input);
    }

    public static void run(String[] input) throws URISyntaxException, IOException {
        String readFilePath = Thread.currentThread().getContextClassLoader().getResource("read.txt").toURI().getPath();
        File file = new File(readFilePath);
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
        File writeFile = new File(readFilePath.replace("read.txt", "write.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter(writeFile));
        List<Integer> list = new ArrayList<>();
        for (String in : input) {
            list.add(Integer.parseInt(in));
        }

        StringBuilder output = new StringBuilder();
        String text;
        while ((text = bufferedReader.readLine()) != null) {
            list.add(Integer.parseInt(text));
        }
        list.stream().sorted().forEach(li -> output.append(li).append("\n"));
        output.deleteCharAt(output.lastIndexOf("\n"));
        System.out.print(output);
        writer.write(output.toString());
        writer.flush();
    }
}
