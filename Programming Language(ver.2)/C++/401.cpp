#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[11], str2[11], str3[21] = {};
    cin >> str1 >> str2;
    cout << strlen(str1) << endl;
    cout << strlen(str2) << endl;
    strcat(str3, str1);
    strcat(str3, str2);
    cout << str3;
    return (0);
}