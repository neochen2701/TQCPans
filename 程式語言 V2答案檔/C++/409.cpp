#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream input, output;
    char c;
    int i;

    input.open("read.txt", ios::in);
    output.open("write.txt", ios::out);
    if (input.fail() || output.fail()) {
        cout << "檔案開啟失敗";
        return(0);
    }

    while (input.get(c)) {
        if (c >= 'a' && c <= 'z') {
            i = (int)(c + 2) - 'a';
            c = (char)((i % 26) + 'a');
            output << c;
        }
        else {
            output << c;
        }
    }
    input.close();
    output.close();
    return (0);
}