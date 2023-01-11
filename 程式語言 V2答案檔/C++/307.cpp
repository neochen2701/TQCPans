#include <iostream>
using namespace std;

int compute(int []);
int main()
{
    int i, input[5];
    for (i = 0; i < 5; i++)
        cin >> input[i];
    cout << compute(input);
    return (0);
}

int compute(int s[])
{
    int i, n = s[0];
    for (i = 1; i < 5; i++)
        n = (s[i] > n) ? s[i] : n;
    return n;
}