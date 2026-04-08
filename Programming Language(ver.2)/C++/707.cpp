#include <iostream>
using namespace std;

typedef struct rect {
    int width;
    int height;
    int size;
} Rect;

int compute(const void*, const void*);

int main()
{
    int i, n;
    Rect* rectList;

    cin >> n;
    rectList = new Rect[n];
    for (i = 0; i < n; i++) {
        cin >> rectList[i].height >> rectList[i].width;
        rectList[i].size = rectList[i].height * rectList[i].width;
    }

    qsort(rectList, n, sizeof(Rect), compute);
    for (i = 0; i < n; i++) {
        cout << rectList[i].height << "x" << rectList[i].width << "=" << rectList[i].size << endl;
    }
    delete[] rectList;
    return (0);
}

int compute(const void* rect1, const void* rect2) {
    return ((Rect*)rect1)->size - ((Rect*)rect2)->size;
}