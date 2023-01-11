#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream input, output;
    int i, j, len = 0, number, * dataList;

    input.open("read.txt", ios::in);
    output.open("write.txt", ios::out);
    if (input.fail() || output.fail()) {
        cout << "檔案開啟失敗";
        return(0);
    }

    while (input >> number) {
        len++;
    }
    len = len + 4;
    dataList = new int[len];
    input.clear();
    input.seekg(0, input.beg);

    for (i = 0; i < 4; i++) {
        cin >> number;
        dataList[i] = number;
    }
    while (input >> number) {
        dataList[i] = number;
        i++;
    }

    for (i = 1; i < len; i++) {
        for (j = i; j > 0; j--) {
            if (dataList[j] < dataList[j - 1]) {
                number = dataList[j];
                dataList[j] = dataList[j - 1];
                dataList[j - 1] = number;
            }
        }
    }

    for (i = 0; i < len; i++) {
        cout << dataList[i] << endl;
        output << dataList[i] << endl;
    }

    input.close();
    output.close();
    delete[] dataList;
    return (0);
}