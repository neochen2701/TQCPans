#include <iostream>
using namespace std;

int mg[100001]; // �j�p���D�N

int main(void)
{
	int n;
	int sum, x;
	int T, m;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	for (n = 1; n <= 100000; n++)
	{
		sum = x = n;
		while (x > 0)
		{
			sum += x % 10;
			x /= 10;
		}

		if (sum > 100000)
			continue;

		if (mg[sum] == 0)
			mg[sum] = n;
	}

	cin >> T;

	while (T--)
	{
		cin >> m;
		cout << mg[m] << '\n';
	}

	return 0;
}
