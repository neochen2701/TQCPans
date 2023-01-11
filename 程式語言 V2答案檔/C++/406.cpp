#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string keyboard1 = "qwertyuioppasdfghjkllzxcvbnmm";
    string keyboard2 = "QWERTYUIOPPASDFGHJKLLZXCVBNMM";
    string targeKeys;
    int i, j;
    char str[50];
    cin.getline(str, 50);
    for (i = 0; i < strlen(str); i++) {
        targeKeys = (str[i] >= 'a' && str[i] <= 'z') ? keyboard1 : keyboard2;
        for (j = 0; j < targeKeys.length(); j++) {
            if (str[i] == targeKeys[j]) {
                str[i] = targeKeys[j + 1];
                break;
            }
        }
    }
    cout << str;
    return (0);
}