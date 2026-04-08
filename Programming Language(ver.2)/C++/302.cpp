#include <iostream>
using namespace std;

int compute(int);
int main()
{
    int n;
    cin >> n;
    cout << compute(n);
    return (0);
}

int compute(int n)
{
    if (n < 0 || n > 100)
        return -1;
    else if (n >= 60)
        return n + 5;
    else
        return n + 10;
}