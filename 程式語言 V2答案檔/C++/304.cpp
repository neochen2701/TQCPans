#include <iostream>
using namespace std;

int compute(int []);
int main()
{
    int i, input[6];
    for (i = 0; i < 6; i++)
        cin >> input[i];
    cout << compute(input);
    return (0);
}

int compute(int s[])
{
    int i, count = 0;
    for (i = 0; i < 6; i++) {
        if (s[i] % 3 == 0) {
            count++;
        }
    }
    return count;
}