#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int i, n[3], line = 0;
    ifstream file;
    string input;

    for (i = 0; i < 3; i++) {
        cin >> n[i];
    }

    file.open("read.txt");
    if (file.fail()) {
        cout << "檔案開啟失敗";
        return(0);
    }
    while (getline(file, input)) {
        for (i = 0; i < input.length() && i < n[line]; i++) {
            input[i] = (char)(n[line] + '0');
        }
        cout << input << endl;
        line++;
    }
    file.close();
    return (0);
}