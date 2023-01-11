#include <iostream>
using namespace std;

int main()
{
    int coin[4] = { 50, 10, 5, 1 };
    int n, i, tmp, count;
    bool isHead = true;
    cin >> n;
    tmp = n;
    for (i = 0; i < 4; i++) {
        if (tmp >= coin[i]) {
            if (!isHead) {
                cout << " ";
            }
            count = tmp / coin[i];
            tmp = tmp % coin[i];
            isHead = false;
            cout << count << "*$" << coin[i];
        }
    }
    return (0);
}