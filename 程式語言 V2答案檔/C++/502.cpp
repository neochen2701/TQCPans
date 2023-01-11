#include <iostream>
using namespace std;

int main()
{
    int input, ans, len, num[9];
    int i, tmp;
    cin >> input;

    if (input == 0) {
        cout << "0=0";
    }
    else {
        tmp = input;
        len = 0;
        ans = 1;
        while (tmp != 0)
        {
            num[len] = tmp % 10;
            ans *= num[len];
            tmp /= 10;
            len++;
        }

        for (i = len - 1; i >= 0; i--) {
            cout << num[i];
            if (i != 0) {
                cout << "*";
            }
        }
        cout << "=" << ans;
    }
    return (0);
}