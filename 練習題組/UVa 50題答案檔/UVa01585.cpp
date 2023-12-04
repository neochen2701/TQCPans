#include <iostream>
using namespace std;

int main(void)
{
	int kase;
	string s;
	int i;
	int score, state;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> kase;
	while (kase--)
	{
		cin >> s;

		score = state = 0;
		for (i = 0; i < s.length(); i++)
		{
			if (s[i] == 'X')
				state = 0;
			else
				state++;
			score += state;
		}

		cout << score << endl;
	}

	return 0;
}
