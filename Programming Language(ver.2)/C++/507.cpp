#include <iostream>
#include <cmath>
using namespace std;

void splite(int, char []);
int compare(char, char []);
int main()
{
    int ans, input[3], i, j;
    char n1[4], n2[4];

    cin >> ans;
    for (i = 0; i < 3; i++) {
        cin >> input[i];
    }

    splite(ans, n1);
    for (i = 0; i < 3; i++) {
        splite(input[i], n2);
        int a = 0, b = 0;
        for (j = 0; j < 4; j++) {
            int point = compare(n2[j], n1);
            if (point == j)
                a++;
            else if (point != -1)
                b++;
        }
        cout << a << "A" << b << "B" << endl;
    }
    return (0);
}

void splite(int num, char cn[]) {
    int i;
    for (i = 3; i >= 0; i--) {
        cn[i] = (char)(num % 10 + '0');
        num /= 10;
    }
}

int compare(char n, char a[]) {
    int i;
    for (i = 0; i < 4; i++) {
        if (n == a[i]) {
            return i;
        }
    }
    return -1;
}
