#include <iostream>
using namespace std;

bool check(char[]);
int main()
{
    char number[3][7];
    int i;
    for (i = 0; i < 3; i++) {
        cin >> number[i];
    }

    for (i = 0; i < 3; i++) {
        if (check(number[i]))
            cout << "Pass" << endl;
        else
            cout << "Fail" << endl;
    }
    return (0);
}

bool check(char num[]) {
    int i, n[5], total, letter;

    for (i = 0; i < 5; i++) {
        n[i] = num[i] - '0';
    }
    letter = (num[5] == 'Z') ? 0 : (num[5] - 'A' + 1);
    total = (n[0] + n[2] + n[4]) + (n[1] + n[3]) * 5;
    total = total % 26;
    return (total == letter);
}