#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    switch (num)
    {
    case 1:
        cout << "one";
        break;
    case 2:
        cout << "two";
        break;
    case 3:
        cout << "three";
        break;
    case 4:
        cout << "four";
        break;
    default:
        cout << "error";
        break;
    }
    return (0);
}