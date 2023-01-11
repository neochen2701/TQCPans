#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int x;
    float prize = 23.34;
    cin >> x;
    cout << setprecision(2) << setiosflags(ios::fixed);
    cout << (x * prize);
    return (0);
}