#include <iostream>
using namespace std;

int main(void)
{
	int kase;
	string s;
	int len;
	int i, j;
	bool period;
	bool first = true;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> kase;

	while (kase--)
	{
		cin >> s;
		len = s.length();

		for (i = 1; i <= len; i++)
		{
			if (!(len % i))
			{
				period = true;

				for (j = i; period && j <= (len - i); j = j + i)
				{
					if (s.substr(0, i) != s.substr(j, i))
						period = false;
				}

				if (period)
				{
					if (first)
					{
						first = false;
					}
					else
					{
						cout << "\n\n";
					}
					cout << i;
					break;
				}
			}
		}
	}

	return 0;
}
