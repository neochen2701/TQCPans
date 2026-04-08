#include <iostream>
using namespace std;

int compute(int);
int main()
{
    int n;
    cin >> n;
    if (compute(n) == 1)
        cout << n << " is a prime number";
    else
        cout << n << " is not a prime number";
    return (0);
}

int compute(int n)
{
    int i;
    for (i = 2; i * i <= n; i++) {
        if (i == n)
            return 1;
        else if (n % i == 0)
            return 0;
    }
    return 1;
}