#include <iostream>
using namespace std;

int main()
{
    int a, b;
    char sign;
    cin >> a >> b >> sign;
    switch (sign)
    {
    case '+':
        cout << a << "+" << b << "=" << (a + b);
        break;
    case '-':
        cout << a << "-" << b << "=" << (a - b);
        break;
    case '*':
        cout << a << "*" << b << "=" << (a * b);
        break;
    default:
        cout << "error";
        break;
    }
    return (0);
}