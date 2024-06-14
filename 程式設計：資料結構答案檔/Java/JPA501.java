import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

class Activity {
    int start, end;

    Activity(int start, int end) {
        this.start = start;
        this.end = end;
    }
}

public class JPA501 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numActivities = scanner.nextInt();
        scanner.nextLine();
        
        ArrayList<Activity> activities = new ArrayList<>();

        for (int i = 0; i < numActivities; i++) {
            String[] parts = scanner.nextLine().split(",");
            int start = Integer.parseInt(parts[0]);
            int end = Integer.parseInt(parts[1]);
            activities.add(new Activity(start, end));
        }

        Collections.sort(activities, new Comparator<Activity>() {
            @Override
            public int compare(Activity a1, Activity a2) {
                return a1.end - a2.end;
            }
        });

        int select = 1;
        Activity current = activities.get(0);
        for (int i = 1; i < numActivities; i++) {
            if (current.end <= activities.get(i).start) {
                current = activities.get(i);
                select++;
            }
        }

        System.out.println(select);
    }
}
