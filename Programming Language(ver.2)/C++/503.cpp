#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, i;
    double n;

    cin >> a >> b;
    for (i = 1; i < a; i++) {
        n = sqrt(i);
        if ((int)(n) == n) {
            cout << pow(n, b) << endl;
        }
    }
    return (0);
}