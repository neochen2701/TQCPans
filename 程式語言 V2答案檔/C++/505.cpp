#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a, b, c, d, e, f, ans;
    cin >> a >> b >> c >> d >> e >> f;
    ans = abs(a) * floor(b) + pow(c, d) * sqrt(e) + log10(f);
    cout << setprecision(2) << setiosflags(ios::fixed);
    cout << ans;
    return (0);
}