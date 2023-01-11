#include <iostream>
using namespace std;

int main()
{
    int a, b, ans1, ans2, ia, ib, temp;
    cin >> a >> b;
	ia = a;
	ib = b;
	while (temp = a % b) {
		a = b;
		b = temp;
	}
	ans1 = b;
	ans2 = ia * ib / ans1;
	cout << ans1 << endl;
	cout << ans2;
    return (0);
}