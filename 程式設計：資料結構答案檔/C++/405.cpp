#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

const int MAX_M = 31;
double adjMatrix[MAX_M][MAX_M];
vector<double> distances(MAX_M, numeric_limits<double>::infinity());
vector<bool> visited(MAX_M, false);

void dijkstra(int start, int m) {
    distances[start] = 0.0;

    for (int i = 1; i <= m; ++i) {
        int minIndex = -1;
        double minDistance = numeric_limits<double>::infinity();

        for (int j = 1; j <= m; ++j) {
            if (!visited[j] && distances[j] < minDistance) {
                minDistance = distances[j];
                minIndex = j;
            }
        }

        if (minIndex == -1) break;

        visited[minIndex] = true;

        for (int j = 1; j <= m; ++j) {
            if (!visited[j] && adjMatrix[minIndex][j] < numeric_limits<double>::infinity()) {
                double newDist = distances[minIndex] + adjMatrix[minIndex][j];
                if (newDist < distances[j]) {
                    distances[j] = newDist;
                }
            }
        }
    }
}

int main() {
    int m, n, s, t;

    for (int i = 0; i < MAX_M; ++i)
        for (int j = 0; j < MAX_M; ++j)
            adjMatrix[i][j] = numeric_limits<double>::infinity();

    cin >> m >> n;
    cin >> s >> t;

    for (int i = 0; i < n; ++i) {
        int v1, v2;
        double w;
        cin >> v1 >> v2 >> w;
        adjMatrix[v1][v2] = w;
        adjMatrix[v2][v1] = w;
    }

    dijkstra(s, m);

    cout << fixed << setprecision(1) << distances[t] << endl;

    return 0;
}
