#include <iostream>
using namespace std;

int main()
{
    int n, i, tmp;
    cin >> n;

    if (n <= 1) {
        cout << "-1";
    }
    else {
        i = 2;
        tmp = n;
        while (tmp != 1)
        {
            if (i == n) {
                tmp = 1;
                cout << "-1";
            }
            else if (tmp % i == 0) {
                cout << i;
                tmp /= i;
                if (tmp != 1) {
                    cout << "*";
                }
            }
            else {
                i++;
            }
        }
    }
    return (0);
}