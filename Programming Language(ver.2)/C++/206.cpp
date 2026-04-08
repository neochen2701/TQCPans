#include <iostream>
using namespace std;

int main()
{
    int a, b, i, total = 0;
    cin >> a >> b;
    i = (a % 2 == 1) ? a : (a + 1);
    for (i; i <= b; i += 2) {
        total += i;
    };
    cout << total;
    return (0);
}