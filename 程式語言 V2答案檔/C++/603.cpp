#include <iostream>
using namespace std;

int main()
{
    int n, m, i, j;
    int **table;

    cin >> n >> m;
    
    table = new int* [n];
    for (i = 0; i < n; i++) {
        table[i] = new int[m];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << table[i][j];
            if (j < m - 1) {
                cout << ',';
            }
        }
        cout << endl;
    }

    for (i = 0; i < n; i++) {
        delete[] table[i];
    }
    delete[] table;
    return (0);
}