#include <iostream>
#include <iomanip>
#define PI 3.14159
using namespace std;

typedef struct circle {
    int x, y, r;
    float size;
} Circle;

int main()
{
    int i, n;
    double total = 0;
    Circle* circle, biggest;

    cin >> n;
    circle = new Circle[n];
    for (i = 0; i < n; i++) {
        cin >> circle[i].x >> circle[i].y >> circle[i].r;
        circle[i].size = (circle[i].r * circle[i].r) * PI;
        total += circle[i].size;
    }
    biggest = circle[0];
    for (i = 1; i < n; i++) {
        biggest = (circle[i].size > biggest.size) ? circle[i] : biggest;
    }

    cout << setprecision(2) << setiosflags(ios::fixed);
    cout << "Sum = " << total << endl;
    cout << "x: " << biggest.x << ", y: " << biggest.y << endl;
    cout << "radius: " << biggest.r;

    delete[]circle;
    return (0);
}