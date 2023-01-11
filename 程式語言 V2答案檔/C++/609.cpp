#include <iostream>
using namespace std;

bool IsLeapYear(int year);
int main()
{
    int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int i, date[3], total = 0;
    for (i = 0; i < 3; i++) {
        cin >> date[i];
    }

    if (IsLeapYear(date[0])) {
        day[1] = 29;
    }

    if (date[0] < 0) {
        cout << "error";
    }
    else if (date[1] < 1 || date[1] > 12) {
        cout << "error";
    }
    else if (date[2] < 1 || date[2] > day[date[1] - 1]) {
        cout << "error";
    }
    else {
        for (i = 1; i < date[1]; i++) {
            total += day[i - 1];
        }
        total += date[2];
        cout << total;
    }

    return (0);
}

bool IsLeapYear(int year) {
    if (year < 0)
        return false;
    else if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    return false;
}
