#include <iostream>
#include <iomanip>
using namespace std;

typedef struct data {
    int value = 0;
    int time = 0;
} Data;

void FIFO(Data[], int);

int main()
{
    Data data[4];
    int i, j, n[10], value;
    for (i = 0; i < 10; i++) {
        cin >> n[i];
    }

    cout << setiosflags(ios::left);
    for (i = 0; i < 10; i++) {
        FIFO(data, n[i]);
        for (j = 0; j < 4; j++) {
            cout << setw(2) << data[j].value;
        }
        cout << endl;
    }
    return (0);
}

void FIFO(Data data[], int value) {
    int i, first = 0, lastTime = data[0].time;
    for (i = 0; i < 4; i++) {
        if (data[i].value == value) {
            return;
        }
        if (data[i].time < data[first].time) {
            first = i;
        }
        if (data[i].time > lastTime) {
            lastTime = data[i].time;
        }
    }
    data[first].value = value;
    data[first].time = lastTime + 1;
}