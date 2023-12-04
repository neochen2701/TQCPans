
#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	string s0;
	int left, right, count, time;
	map<char, int> d;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	d['W'] = 64;
	d['H'] = 32;
	d['Q'] = 16;
	d['E'] = 8;
	d['S'] = 4;
	d['T'] = 2;
	d['X'] = 1;

	while (cin >> s0 && s0 != "*")
	{
		count = 0;

		left = 0;
		while (left < s0.length() - 2)
		{
			right = s0.find('/', left + 1);

			time = 0;
			for (int i = left + 1; i < right; i++)
			{
				time += d[s0[i]];
			}
			(time == 64) && count++;

			left = right;
		}

		cout << count << '\n';
	}

	return 0;
}
