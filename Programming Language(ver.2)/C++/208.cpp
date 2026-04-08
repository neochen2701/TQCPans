#include <iostream>
using namespace std;

int main()
{
    int num, n, i;
    bool flag;
    cin >> num;
    for (n = 2; n < num; n++) {
        flag = true;
        for (i = 2; i * i <= n; i++) {
            if (i == n) {
                break;
            }
            else if (n % i == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << n << " ";
        }
    }
    return (0);
}