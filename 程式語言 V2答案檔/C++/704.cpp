#include <iostream>
using namespace std;

int main()
{
    int n, i, j;
    int* data, ** count;
    bool hasAns = false;

    cin >> n;
    data = new int[n];
    count = new int* [n];
    for (i = 0; i < n; i++) {
        count[i] = new int[2];
        count[i][0] = count[i][1] = 0;
    }

    for (i = 0; i < n; i++) {
        cin >> data[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (count[j][1] == 0) {
                count[j][0] = data[i];
                count[j][1] = 1;
                break;
            }
            else if (count[j][0] == data[i]) {
                count[j][1]++;
                break;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (count[i][1] > n / 2) {
            hasAns = true;
            cout << count[i][0];
            break;
        }
    }
    if (!hasAns) {
        cout << "error";
    }

    for (i = 0; i < n; i++) {
        delete[] count[i];
    }
    delete[] count;
    delete[] data;
    return (0);
}