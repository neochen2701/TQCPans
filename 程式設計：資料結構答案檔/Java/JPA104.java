import java.util.Scanner;

public class JPA104 {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int m = sc.nextInt();
      int n = sc.nextInt();

      int[][] map = new int[m + 2][n + 2];

      for (int i = 0; i <= m + 1; i++) {
         for (int j = 0; j <= n + 1; j++) {
            map[i][j] = -2;
         }
      }
      for (int i = 1; i <= m; i++) {
         for (int j = 1; j <= n; j++) {
            map[i][j] = sc.nextInt();
         }
      }
      sc.close();

      int maxSize = 0;
      for (int i = 1; i <= m; i++) {
         for (int j = 1; j <= n; j++) {
            int size = findLowerArea(map, i, j, m, n);
            if (size > maxSize) {
               maxSize = size;
            }
         }
      }
      System.out.println(maxSize);
   }

   public static int findLowerArea(int[][] map, int x, int y, int w, int h) {
      if (map[x][y] > 0)
         return 0;
      if (map[x][y] == -2)
         return 0;
      if (map[x][y] == -1)
         return 0;
      map[x][y] = -1;

      return (1 + findLowerArea(map, x - 1, y, w, h) + findLowerArea(map, x + 1, y, w, h)
            + findLowerArea(map, x, y - 1, w, h) + findLowerArea(map, x, y + 1, w, h));
   }

   public static void showMap(int[][] map, int w, int h) {
      for (int i = 1; i <= w; i++) {
         for (int j = 1; j <= h; j++) {
            System.out.print(map[i][j] + " ");
         }
         System.out.println();
      }
      System.out.println();
   }
}