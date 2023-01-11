#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    char input[11];
    int i, len, ans = 0;

    cin >> input;
    len = strlen(input) - 1;
    for (i = len; i >= 0; i--) {
        if (input[i] == '1') {
            ans += pow(2, (len - i));
        }
    }
    cout << ans;
    return (0);
}