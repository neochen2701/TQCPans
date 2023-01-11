#include <iostream>
using namespace std;

int** createTable(int h, int w, bool isInput);
void deleteTable(int** table, int h);
int main()
{
    int a1, b1, a2, b2, i, j;
    int** table1, ** table2, **table3;

    cin >> a1 >> b1;
    table1 = createTable(a1, b1, true);
    cin >> a2 >> b2;
    table2 = createTable(a2, b2, true);

    if (b1 != a2) {
        cout << "error";
    }
    else {
        table3 = createTable(a1, b2, false);
        int sum, k;
        for (i = 0; i < a1; i++) {
            for (j = 0; j < b2; j++) {
                for (sum = k = 0; k < b1; k++) {
                    sum += table1[i][k] * table2[k][j];
                }
                table3[i][j] = sum;
            }
        }

        for (i = 0; i < a1; i++) {
            for (j = 0; j < b2; j++) {
                cout << table3[i][j];
                if (j != b2 - 1)
                    cout << " ";
            }
            cout << endl;
        }
        deleteTable(table3, a1);
    }
    
    deleteTable(table1, a1);
    deleteTable(table2, a2);
    return (0);
}

int** createTable(int h, int w, bool isInput){
    int i, j, ** table;
    table = new int* [h];
    for (i = 0; i < h; i++) {
        table[i] = new int[w];
    }

    if (isInput) {
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                cin >> table[i][j];
            }
        }
    }
    return table;
}

void deleteTable(int **table, int h){
    int i;
    for (i = 0; i < h; i++) {
        delete[] table[i];
    }
    delete[] table;
}

