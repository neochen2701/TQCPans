#include <iostream>
using namespace std;

bool searchNearGrid(int**, int, int, int, int);

int main()
{
    int n, m, i, j;
    int** table;
    bool isEdge;
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
            isEdge = (i == 0) || (i == n - 1) || (j == 0 || (j == m - 1));
            if (isEdge && table[i][j] == 1) {
                cout << '*';
            }
            else if (table[i][j] == 0) {
                cout << ' ';
            }
            else {
                if (searchNearGrid(table, i, j, n, m)) {
                    cout << '*';
                }
                else {
                    cout << ' ';
                }
            }
        }
        if (i != n - 1) cout << endl;
    }

    for (i = 0; i < n; i++) {
        delete[] table[i];
    }
    delete[] table;
    return (0);
}

bool searchNearGrid(int** table, int h, int w, int maxH, int maxW) {
    int direction[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
    int i, dh, dw;
    for (i = 0; i < 4; i++) {
        dh = h + direction[i][0];
        dw = w + direction[i][1];
        if (dh >= 0 && dh < maxH && dw >= 0 && dw < maxW) {
            if (table[dh][dw] == 0) {
                return true;
            }
        }
    }
    return false;
}