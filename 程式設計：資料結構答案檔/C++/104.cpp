#include <iostream>
#include <vector>
using namespace std;

int find_lower_area(vector<vector<int>>& map, int x, int y, int w, int h) {
    if (map[x][y] > 0 || map[x][y] == -2 || map[x][y] == -1) {
        return 0;
    }
    map[x][y] = -1;
    return 1 + find_lower_area(map, x-1, y, w, h) + find_lower_area(map, x+1, y, w, h)
               + find_lower_area(map, x, y-1, w, h) + find_lower_area(map, x, y+1, w, h);
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> map(m+2, vector<int>(n+2, -2));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    int maxSize = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int size = find_lower_area(map, i, j, m, n);
            if (size > maxSize) {
                maxSize = size;
            }
        }
    }

    cout << maxSize << endl;
    return 0;
}
