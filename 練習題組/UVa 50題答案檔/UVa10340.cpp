
#include <iostream>
using namespace std;

int main(void)
{
	string s, t;
	int sIndex, tIndex;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> s >> t)
	{
		sIndex = s.length() - 1;
		tIndex = t.length() - 1;

		while (sIndex >= 0 && tIndex >= 0)
		{
			if (s[sIndex] == t[tIndex])
			{
				sIndex--;
			}
			tIndex--;
		}

		cout << (sIndex < 0 ? "Yes" : "No") << '\n';
	}

	return 0;
}
