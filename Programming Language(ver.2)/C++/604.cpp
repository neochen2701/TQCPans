#include <iostream>
using namespace std;

void sort(int[], int);
int main()
{
    int i, input[9], total = 0;
    for (i = 0; i < 9; i++) {
        cin >> input[i];
    }

    sort(input, 9);
    for (i = 0; i < 9; i++) {
        total += input[i];
        cout << input[i] << endl;
    }
    cout << "sum = " << total;
    return (0);
}

void sort(int list[], int length) {
    int i, j, n;
    for (i = 1; i < length; i++) {
        for (j = i; j > 0; j--) {
            if (list[j] < list[j - 1]) {
                n = list[j];
                list[j] = list[j - 1];
                list[j - 1] = n;
            }
        }
    }
}