#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[50];
    int i, max, count[26] = { 0 };
    cin >> str;

    for (i = 0; i < strlen(str); i++) {
        count[str[i] - 'a']++;
    }
    max = 0;
    for (i = 1; i < 26; i++) {
        max = (count[i] > count[max]) ? i : max;
    }
    cout << (char)(max + 'a') << endl;
    cout << count[max];
    return (0);
}