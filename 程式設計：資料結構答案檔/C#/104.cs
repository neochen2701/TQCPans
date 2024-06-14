using System;

class Program {
    static int FindLowerArea(int[,] map, int x, int y, int w, int h) {
        if (map[x,y] > 0 || map[x,y] == -2 || map[x,y] == -1) {
            return 0;
        }
        map[x,y] = -1;
        return 1 + FindLowerArea(map, x-1, y, w, h) + FindLowerArea(map, x+1, y, w, h)
                 + FindLowerArea(map, x, y-1, w, h) + FindLowerArea(map, x, y+1, w, h);
    }

    static void Main() {
        string[] inputs = Console.ReadLine().Split();
        int m = int.Parse(inputs[0]);
        int n = int.Parse(inputs[1]);

        int[,] map = new int[m+2, n+2];
        for (int i = 0; i < m+2; i++) {
            for (int j = 0; j < n+2; j++) {
                map[i,j] = -2;
            }
        }

        for (int i = 1; i <= m; i++) {
            inputs = Console.ReadLine().Split();
            for (int j = 1; j <= n; j++) {
                map[i,j] = int.Parse(inputs[j-1]);
            }
        }

        int maxSize = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int size = FindLowerArea(map, i, j, m, n);
                if (size > maxSize) {
                    maxSize = size;
                }
            }
        }
        Console.WriteLine(maxSize);
    }
}
