import java.util.*;
import java.util.stream.Collectors;

class Order implements Comparable<Order> {
    int orderNumber, time, value;

    Order(int orderNumber, int time, int value) {
        this.orderNumber = orderNumber;
        this.time = time;
        this.value = value;
    }

    @Override
    public int compareTo(Order other) {
        return Integer.compare(this.orderNumber, other.orderNumber);
    }
}

public class JPA504 {
    private static int n, x;
    private static List<Order> orders = new ArrayList<>();

    private static void getOrdersFromFile() {
        try (Scanner sc = new Scanner(System.in)) {
            n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                int orderNumber = sc.nextInt();
                int time = sc.nextInt();
                int value = sc.nextInt();
                orders.add(new Order(orderNumber, time, value));
            }
            x = sc.nextInt();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void printAnswer(List<Order> selectedOrders, int totalValue) {
        System.out.println(
            selectedOrders.stream()
            .map(order -> Integer.toString(order.orderNumber))
            .collect(Collectors.joining(" "))
        );
        System.out.println(totalValue);
    }

    private static void dynamicProg() {
        int[][] dp = new int[n+1][x+1];
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= x; j++) {
                if (orders.get(i-1).time > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-orders.get(i-1).time] + orders.get(i-1).value);
            }
        }

        List<Order> selectedOrders = new ArrayList<>();
        int totalValue = 0, j = x;
        for (int i = n; i > 0; i--) {
            if (dp[i][j] != dp[i-1][j]) {
                selectedOrders.add(orders.get(i-1));
                totalValue += orders.get(i-1).value;
                j -= orders.get(i-1).time;
            }
        }

        Collections.sort(selectedOrders);
        printAnswer(selectedOrders, totalValue);
    }

    public static void main(String[] args) {
        getOrdersFromFile();
        dynamicProg();
    }
}
