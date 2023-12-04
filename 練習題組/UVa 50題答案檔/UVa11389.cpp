
#include <iostream>
#include <vector>
#include <algorithm> //for sort()
using namespace std;

int main(void)
{
	int n, d, r;
	int len;
	int i;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> n >> d >> r && n != 0)
	{
		vector<int> AM, PM;
		int extra = 0;

		for (i = 0; i < n; i++)
		{
			cin >> len;
			AM.push_back(len);
		}
		for (i = 0; i < n; i++)
		{
			cin >> len;
			PM.push_back(len);
		}

		sort(AM.begin(), AM.end());
		sort(PM.begin(), PM.end(), greater<int>());

		for (i = 0; i < n; i++)
		{
			if (AM[i] + PM[i] > d)
			{
				extra += (AM[i] + PM[i] - d) * r;
			}
		}

		cout << extra << '\n';
	}

	return 0;
}
