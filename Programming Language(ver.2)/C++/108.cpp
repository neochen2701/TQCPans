#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a;
    double radius, size, pi = 3.1415;

    cin >> a;
    radius = a / 2.0;
    size = radius * radius * pi;
    cout << setiosflags(ios::left);
    cout << setw(10) << a << endl;
    cout << setprecision(2) << setiosflags(ios::fixed);
    cout << setw(10) << radius << endl;
    cout << setprecision(4);
    cout << setw(10) << size;
    return (0);
}