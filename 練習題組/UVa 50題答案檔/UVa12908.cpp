
#include <iostream>
using namespace std;

int main(void)
{
	int s, page, sum;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> s && s)
	{
		sum = page = 0;

		do
		{
			sum += ++page;
		} while (sum <= s);

		cout << sum - s << " " << page << '\n';
	}

	return 0;
}
