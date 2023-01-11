#include <iostream>
using namespace std;

int main()
{
    int i, num, count[7] = { 0 };
    for (i = 1; i <= 10; i++) {
        cin >> num;
        if (num < 1 || num > 6) {
            count[0]++;
        }
        else {
            count[num]++;
        }
    }
    for (i = 1; i <= 6; i++) {
        cout << "number" << i << ":" << count[i] << endl;
    }
    cout << "error:" << count[0];
    return (0);
}