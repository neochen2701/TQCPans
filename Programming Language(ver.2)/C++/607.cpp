#include <iostream>
using namespace std;

char compare(char[], char[]);
int sign(char);
int number(char[]);

int main()
{
    char input[2][4], ans;
    int i;

    for (i = 0; i < 2; i++) {
        cin >> input[i];
    }

    ans = compare(input[0], input[1]);
    cout << input[0] << " " << ans << " " << input[1];
    return (0);
}

char compare(char a[], char b[]) {
    int valueA = sign(a[0]);
    int valueB = sign(b[0]);

    if (valueA != valueB) {
        return (valueA > valueB) ? '>' : '<';
    }
    else {
        valueA = number(a);
        valueB = number(b);
        if (valueA > valueB)
            return '>';
        else if (valueA < valueB)
            return '<';
        else
            return '=';
    }
}

int sign(char s) {
    switch (s)
    {
    case 'S':
        return 4;
        break;
    case 'H':
        return 3;
        break;
    case 'D':
        return 2;
        break;
    case 'C':
        return 1;
        break;
    default:
        break;
    }
}

int number(char s[]) {
    int i, n = 0;
    for (i = 1; s[i] != '\0'; i++) {
        n = n * 10 + (s[i] - '0');
    }
    return n;
}