#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    double result;
    cin >> a >> b;
    result = sqrt(a + b);
    cout << setprecision(2) << setiosflags(ios::fixed);
    cout << "result=" << result;
    return (0);
}