#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    queue<int> allIds;
    for (int i = 1; i <= n; i++) {
        allIds.push(i);
    }

    while (allIds.size() > 1) {
        for (int i = 1; i < x; i++) {
            int t = allIds.front();
            allIds.pop();
            allIds.push(t);
        }
        allIds.pop();
    }

    cout << allIds.front() << endl;
    return 0;
}
