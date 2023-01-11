#include <iostream>
using namespace std;

int compute(int);
int main()
{
    int n;
    cin >> n;
    cout << n << "!=" << compute(n);
    return (0);
}

int compute(int n)
{
    int i, result = 1;
    for (i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}