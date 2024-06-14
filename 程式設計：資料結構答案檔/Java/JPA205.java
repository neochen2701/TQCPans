import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class JPA205 {
    static class Rectangle {
        int area, top, left, bottom, right;

        Rectangle(int area, int top, int left, int bottom, int right) {
            this.area = area;
            this.top = top;
            this.left = left;
            this.bottom = bottom;
            this.right = right;
        }
    }

    public static Rectangle largestRectangleArea(List<Integer> heights, int row) {
        int n = heights.size();
        List<Integer> left = new ArrayList<>(n), right = new ArrayList<>(n);
        for (int i = 0; i < n; i++) right.add(n);
        Stack<Integer> stk =         new Stack<>();
        Rectangle maxRect = new Rectangle(0, row, 0, row, 0);

        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && heights.get(stk.peek()) >= heights.get(i)) {
                right.set(stk.peek(), i);
                stk.pop();
            }
            left.add(stk.isEmpty() ? 0 : stk.peek() + 1);
            stk.push(i);
        }

        for (int i = 0; i < n; ++i) {
            int area = heights.get(i) * (right.get(i) - left.get(i));
            if (area > maxRect.area) {
                maxRect = new Rectangle(area, row - heights.get(i) + 1, left.get(i), row, right.get(i) - 1);
            }
        }

        return maxRect;
    }

    public static Rectangle findLargestRectangleArea(List<List<Integer>> matrix) {
        int n = matrix.size();
        if (n == 0) return new Rectangle(0, 0, 0, 0, 0);
        int m = matrix.get(0).size();
        if (m == 0) return new Rectangle(0, 0, 0, 0, 0);

        List<Integer> heights = new ArrayList<>(m);
        for (int i = 0; i < m; i++) heights.add(0);
        Rectangle maxRect = new Rectangle(0, 0, 0, 0, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heights.set(j, matrix.get(i).get(j) == 1 ? heights.get(j) + 1 : 0);
            }
            Rectangle rect = largestRectangleArea(heights, i);
            if (rect.area > maxRect.area) {
                maxRect = rect;
            }
        }

        return maxRect;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        List<List<Integer>> matrix = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                row.add(scanner.nextInt());
            }
            matrix.add(row);
        }

        Rectangle maxRect = findLargestRectangleArea(matrix);
        System.out.println(maxRect.area);
        System.out.println("(" + maxRect.top + ", " + maxRect.left + ")");
        System.out.println("(" + maxRect.bottom + ", " + maxRect.right + ")");
    }
}