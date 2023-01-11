#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[100];
    int i;
    cin >> str;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = tolower(str[i]);
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = toupper(str[i]);
    }
    cout << str;
    return (0);
}