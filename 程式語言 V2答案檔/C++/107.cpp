#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << setw(10) << a << " " << setw(10) << b << " " << setw(10) << c << endl;
    cout << setw(10) << d << " "<<  setw(10) << e << " " << setw(10) << f << endl;
    cout << setiosflags(ios::left);
    cout << setw(10) << a << " " << setw(10) << b << " " << setw(10) << c << endl;
    cout << setw(10) << d << " " << setw(10) << e << " " << setw(10) << f << endl;
    return (0);
}