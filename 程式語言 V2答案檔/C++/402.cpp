#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[128], str2[128];
    int n, result;
    cin.getline(str1, 128);
    cin.getline(str2, 128);
    cin >> n;
    if (n > (int)strlen(str1) || n > (int)strlen(str2)) {
        cout << "error";
    }
    else {
        result = strncmp(str1, str2, n);
        if (result > 0) {
            cout << str1 << " > " << str2;
        }
        else if (result < 0) {
            cout << str1 << " < " << str2;
        }
        else {
            cout << str1 << " = " << str2;
        }
    }
    return (0);
}