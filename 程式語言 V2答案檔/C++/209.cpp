#include <iostream>
using namespace std;

int main()
{
    int dir, i, j;
    cin >> dir;
    if (dir != 1 && dir != 0) {
        cout << "error";
    }
    else {
        for (i = 1; i <= 5; i++) {
            for (j = 1; j <= 5; j++) {
                if (dir == 0)
                    cout << i << " x " << j << " = " << (i * j) << "\t";
                else 
                    cout << j << " x " << i << " = " << (i * j) << "\t";
            }
            cout << endl;
        }
    }
    return (0);
}