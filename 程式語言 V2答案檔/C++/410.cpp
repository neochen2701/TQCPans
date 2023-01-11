#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    fstream input, output;
    string str;
    int n, line, i;

    cin >> n;
    input.open("read.txt", ios::in);
    output.open("write.txt", ios::out);
    if (input.fail() || output.fail()) {
        cout << "檔案開啟失敗";
        return(0);
    }

    line = 1;
    while (getline(input, str)) {
        if (line > n) {
            break;
        }

        if (isalpha(str[0])) str[0] = toupper(str[0]);
        for (i = 1; i < str.length(); i++) {
            if (isalpha(str[i]) && str[i - 1] == ' ') {
                str[i] = toupper(str[i]);
            }
        }

        if (line != 1) {
            cout << endl;
            output << "\n";
        }
        cout << str;
        output << str;
        line++;
    }
    input.close();
    output.close();
    return (0);
}