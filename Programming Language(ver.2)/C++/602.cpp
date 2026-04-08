#include <iostream>
using namespace std;

int main()
{
    string input, upList, lowList;
    int i;
    char c;

    cin >> input;
    for (i = 0; i < input.length(); i++) {
        c = input[i];
        if (c >= 'a' && c <= 'z') {
            lowList += c;
        }
        else if (c >= 'A' && c <= 'Z') {
            upList += c;
        }
    }
    cout << upList << endl;
    cout << lowList << endl;
    cout << upList.length();
    return (0);
}