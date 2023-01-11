#include <iostream>
using namespace std;

typedef struct time {
    int hour;
    int min;
} Time;

int change(Time);

int main()
{
    Time timer[3];
    int i, count = 0;

    for (i = 0; i < 3; i++) {
        cin >> timer[i].hour >> timer[i].min;
    }
    for (i = 0; i < 3; i++) {
        if (change(timer[i]) == 1) {
            count++;
        }
    }
    cout << count;
    return (0);
}

int change(Time time) {
    int hour, min;
    if (time.hour >= 0 && time.hour <= 11) {
        if (time.hour == 0) {
            time.hour = 12;
        }
        cout << "AM " << time.hour << ":" << time.min << endl;
        return 1;
    }
    else {
        if (time.hour > 12) {
            time.hour -= 12;
        }
        cout << "PM " << time.hour << ":" << time.min << endl;
        return 0;
    }
}