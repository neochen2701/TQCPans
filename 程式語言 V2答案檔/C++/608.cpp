#include <iostream>
using namespace std;

int main()
{
    int i, input[10];
    int p, np, move, s[5] = { 0 };

    for (i = 0; i < 10; i++) {
        cin >> input[i];
    }

    for (i = 0; i < 10; i++) {
        s[0] = 1;
        move = input[i];
        if (move != 0) {
            for (p = 3; p >= 0; p--) {
                np = p + move;
                if (np >= 4) {
                    s[4] += s[p];
                }
                else {
                    s[np] = s[p];
                }
                s[p] = 0;
            }
        }
    }
    cout << "score = " << s[4];
    return (0);
}