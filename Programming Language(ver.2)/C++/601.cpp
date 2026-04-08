#include <iostream>
using namespace std;

int main()
{
    int n;
    char c = ' ';
    string input;

    cin >> input >> n;
    if (n <= input.length()) {
        c = input[n];
        if (c >= 'a' && c <= 'z') {
            c = toupper(c);
        }
        else if (c >= 'A' && c <= 'Z') {
            c = tolower(c);
        }
        input[n] = c;
    }
    cout << "The letter that was selected is: " << c << endl;
    cout << input;
    return (0);
}