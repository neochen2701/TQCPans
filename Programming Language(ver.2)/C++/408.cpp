#include <iostream>
using namespace std;

int main()
{
    string a, b;
    int i;
    cin >> a >> b;

    if (a.length() <= 3 || a.length() > 20) {
        cout << "error";
    }
    else if (b.length() <= 3 || b.length() > 20) {
        cout << "error";
    }
    else {
        cout << a.length() << endl;
        cout << b.length() << endl;
        a += b;
        for (i = a.length() - 1; i >= 0; i--) {
            cout << a[i];
        }
    }
    return (0);
}