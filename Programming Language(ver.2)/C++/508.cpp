#include <iostream>
#include <cmath>
using namespace std;

int changeToTen(string);
string changeToTwo(int);

int main()
{
    string a, b;
    int n1, n2, total;

    cin >> a >> b;
    n1 = changeToTen(a);
    n2 = changeToTen(b);
    total = n1 + n2;
    cout << n1 << " + " << n2 << " = " << total << endl;
    cout << changeToTwo(total);
    return (0);
}

int changeToTen(string n) {
    int i, num = 0;
    for (i = 0; i < 8; i++) {
        if (n[7 - i] == '1') {
            num += pow(2, i);
        }
    }
    return num;
}

string changeToTwo(int n) {
    string num = "00000000";
    int i;
    for (i = 7; i >= 0 && n != 0; i--) {
        num[i] = (n % 2) + '0';
        n /= 2;
    }

    if (n != 0)
        return "11111111";
    else
        return num;
}