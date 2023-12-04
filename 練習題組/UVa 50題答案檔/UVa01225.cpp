#include <iostream>
using namespace std;

int main(void)
{
	int kase, n;

	int i, j;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> kase;
	while (kase--)
	{
		int count[10] = {0}; // block scope

		cin >> n;

		for (i = 1; i <= n; i++)
		{
			j = i;
			while (j)
			{
				count[j % 10]++;
				j /= 10;
			}
		}

		cout << count[0];
		for (i = 1; i < 10; i++)
		{
			cout << " " << count[i];
		}
		cout << '\n';
	}
	return 0;
}
