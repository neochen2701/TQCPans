#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a >= 60 && a < 100) << endl;
    cout << setprecision(2) << setiosflags(ios::fixed);
    cout << (b + 1) / 10.0 << endl;
    cout << (a >= c ? a : c);
    return (0);
}