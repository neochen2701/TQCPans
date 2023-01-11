#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, c;
    double s, size;

    cin >> a >> b >> c;
    s = (a + b + c) / 2.0;
    size = sqrt(s * (s - a) * (s - b) * (s - c));
    cout << setprecision(2) << setiosflags(ios::fixed);
    cout << size;
    return (0);
}