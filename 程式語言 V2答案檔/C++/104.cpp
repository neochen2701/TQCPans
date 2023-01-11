#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float a, b, total;
    cin >> a >> b;
    total = a + b;
    cout << setprecision(2) << setiosflags(ios::fixed);
    cout << "total=" << total;
    return (0);
}