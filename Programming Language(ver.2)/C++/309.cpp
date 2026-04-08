#include <iostream>
#include <iomanip>
using namespace std;

double compute(int []);
int main()
{
    int i, input[6];
    for (i = 0; i < 6; i++)
        cin >> input[i];

    cout << setprecision(3) << setiosflags(ios::fixed);
    cout << compute(input);
    return (0);
}

double compute(int s[])
{
    int i;
    double n, result = (double)s[0] / s[3];
    for (i = 1; i < 3; i++) {
        n = (double)s[i] / s[i + 3];
        result = (n < result) ? n : result;
    }
    return result;
}