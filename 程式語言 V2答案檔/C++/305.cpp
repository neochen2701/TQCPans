#include <iostream>
using namespace std;

int compute(int []);
int main()
{
    int i, input[3];
    for (i = 0; i < 3; i++)
        cin >> input[i];
    cout << compute(input);
    return (0);
}

int compute(int s[])
{
    if (s[1] == 1)
        return s[0] + s[2];
    else if (s[1] == 2)
        return s[0] * s[2];
}