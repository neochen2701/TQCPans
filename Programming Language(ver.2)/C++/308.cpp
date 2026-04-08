#include <iostream>
using namespace std;

int compute(int);
int main()
{
    int i, n, fib[10];
    cin >> n;
    for (i = 0; i <= n; i++) {
        fib[i] = compute(i);
    }
    for (i = n; i >= 1; i--) {
        cout << "fib(" << i << ")=" << fib[i] << endl;
    }
    return (0);
}

int compute(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return compute(n - 1) + compute(n - 2);
}