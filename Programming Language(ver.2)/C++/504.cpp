#include <iostream>
using namespace std;

int main()
{
    int a1, a2, tmp;
    cin >> a1;

    tmp = a1;
    a2 = 0;
    while (tmp != 0) {
        a2 = a2 * 10 + (tmp % 10);
        tmp /= 10;
    }
    if (a1 == a2) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return (0);
}