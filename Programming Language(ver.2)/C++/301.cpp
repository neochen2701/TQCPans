#include <iostream>
using namespace std;

int compute(int []);
int main()
{
    int input[2];
    cin >> input[0] >> input[1];
    cout << compute(input);
    return (0);
}

int compute(int s[])
{
    int i, j;
    for (i = 1; i <= s[1]; i++) {
        for (j = 1; j <= s[0]; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return s[0] * s[1];
}