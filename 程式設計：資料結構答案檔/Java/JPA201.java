import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class JPA201 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        List<Integer> tasks = requestQuests(input);

        if (tasks != null) {
            int totalReward = calculateTotalReward(tasks);
            System.out.println(totalReward);
        }
    }

    private static List<Integer> requestQuests(String input) {
        List<Integer> tasks = new ArrayList<>();
        String[] parts = input.split(",");
        for (String part : parts) {
            try {
                int taskReward = Integer.parseInt(part);
                if (taskReward < 0) {
                    System.out.println("error");
                    return null;
                }
                tasks.add(taskReward);
            } catch (NumberFormatException e) {
                System.out.println("error");
                return null;
            }
        }
        return tasks;
    }

    private static int calculateTotalReward(List<Integer> tasks) {
        int totalReward = 0;
        int morningTasks = 3;
        int noonTasks = 2;
        int nightTasks = 1;
        int i = 0;

        while (i < tasks.size()) {
            for (int j = 0; j < morningTasks && i < tasks.size(); j++, i++) {
                totalReward += tasks.get(i) * 3;
            }
            for (int j = 0; j < noonTasks && i < tasks.size(); j++, i++) {
                totalReward += tasks.get(i) * 2;
            }
            for (int j = 0; j < nightTasks && i < tasks.size(); j++, i++) {
                totalReward += tasks.get(i);
            }
        }

        return totalReward;
    }
}
