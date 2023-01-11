#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, c, total;
    float ave;
    cin >> a >> b >> c;
    total = a + b + c;
    ave = total / 3.0;
    cout << a << "+" << b << "+" << c << "=" << total << endl;
    cout << setprecision(2) << setiosflags(ios::fixed);
    cout << ave;
    return (0);
}