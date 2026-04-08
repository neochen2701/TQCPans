#include <iostream>
using namespace std;

int main()
{
    int score;
    cin >> score;
    if (score < 0 || score > 100) {
        cout << "error" << endl;
    }
    else if (score >= 60) {
        cout << "pass" << endl;
        if (score % 2 == 1)
            cout << "odd";
        else
            cout << "even";
    }
    else {
        cout << "fail" << endl;
        if (score % 2 == 1)
            cout << "odd";
        else
            cout << "even";
    }
    return (0);
}