#include <iostream>
#include <cmath>
using namespace std;

int compute(int);
int main()
{
    int n;
    cin >> n;
    cout << compute(n);
    return (0);
}

int compute(int n)
{
    int i, total = 0;
    for (i = 1; i <= n; i++) {
        int tmp = i, len = 0, m = 0;
        while (tmp > 0)
        {
            tmp = tmp / 10;
            len++;
        }
        tmp = i;
        while (tmp > 0)
        {
            m = m + pow(tmp % 10, len);
            tmp = tmp / 10;
        }
        if (m == i) {
            cout << i << endl;
            total = total + i;
        }
    }
    return total;
}