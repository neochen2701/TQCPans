import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class JPA202 {

    private static void inorderTree(int idx, String[] lst) {
        if (idx < lst.length && !lst[idx].equals("")) {
            inorderTree(2 * idx, lst);
            System.out.print(lst[idx]);
            inorderTree(2 * idx + 1, lst);
        }
    }

    private static void leafNode(String[] lst) {
        List<String> leaves = new ArrayList<>();

        for (int i = 1; i < lst.length; i++) {
            if ((2 * i >= lst.length || lst[2 * i].equals("")) && (2 * i + 1 >= lst.length || lst[2 * i + 1].equals(""))) {
                leaves.add(lst[i]);
            }
        }

        leaves.sort(String::compareTo);
        for (String leaf : leaves) {
            System.out.print(leaf);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] lst = new String[input.split(",").length + 1];
        System.arraycopy(input.split(","), 0, lst, 1, input.split(",").length);

        inorderTree(1, lst);
        System.out.println();
        leafNode(lst);
    }
}
