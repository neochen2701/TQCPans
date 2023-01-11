#include <iostream>
using namespace std;

int main()
{
    int score;
    cin >> score;
    if (score < 0 || score > 100) {
        cout << "error";
    }
    else {
        if (score > 60) {
            score += 10;
        }
        else {
            score += 5;
        }
        cout << score;
    }
    return (0);
}