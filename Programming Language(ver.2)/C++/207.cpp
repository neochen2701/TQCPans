#include <iostream>
using namespace std;

int main()
{
    int num, i;
    bool isPrime = true;
    cin >> num;
    for (i = 2; i * i <= num; i++) {
        if (i == num) {
            break;
        }
        else if (num % i == 0) {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
        cout << num << " is a prime number";
    else
        cout << num << " is not a prime number";
    return (0);
}