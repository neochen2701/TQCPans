#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> adj_array_of_graph(m + 1, vector<int>(m + 1, 0));
    for(int i = 0; i < n; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        adj_array_of_graph[v1][v2] = 1;
        adj_array_of_graph[v2][v1] = 1;
    }

    vector<int> degree_of_vertex(m + 1, 0);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            if(adj_array_of_graph[i][j] == 1)
                degree_of_vertex[i]++;

    int num_of_odd_degree_vertex = 0;
    for(int i = 1; i <= m; i++)
        if(degree_of_vertex[i] % 2 == 1)
            num_of_odd_degree_vertex++;

    if(num_of_odd_degree_vertex == 0 || num_of_odd_degree_vertex == 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j < m; j++)
            cout << adj_array_of_graph[i][j] << " ";
        cout << adj_array_of_graph[i][m] << endl;
    }

    return 0;
}
