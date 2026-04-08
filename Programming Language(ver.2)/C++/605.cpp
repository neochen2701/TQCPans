#include <iostream>
using namespace std;

void sort(int[], int);
int main()
{
    int i, input[6], ans = 0;
    for (i = 0; i < 6; i++) {
        cin >> input[i];
    }
    sort(input, 6);
    for (i = 0; i < 6; i++) {
        if (i < 3)
            ans -= input[i];
        else
            ans += input[i];
    }
    cout << ans;
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