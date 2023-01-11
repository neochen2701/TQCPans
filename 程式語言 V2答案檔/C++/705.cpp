#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char data[3][21], input[21];
    int i, j, count[3], total = 0;

    for (i = 0; i < 3; i++) {
        cin >> data[i] >> count[i];
    }

    for (i = 0; i < 5; i++) {
        cin >> input;

        for (j = 0; j < 3; j++) {
            if (strcmp(input, data[j]) == 0) {
                total += count[j];
            }
        }
    }
    cout << total;
    return (0);
}