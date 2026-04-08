#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int x1, y1, x2, y2, vx, vy;
    double dis;
    cin >> x1 >> y1 >> x2 >> y2;
    vx = x2 - x1;
    vy = y2 - y1;
    dis = sqrt(vx * vx + vy * vy);
    cout << setprecision(2) << setiosflags(ios::fixed);
    cout << dis;
    return (0);
}