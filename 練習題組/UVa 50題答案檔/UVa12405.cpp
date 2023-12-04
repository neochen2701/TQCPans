
#include <iostream>
using namespace std;

int main(void)
{
	int t;
	string s0;
	int i, scarecrow;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> s0 >> s0;

		scarecrow = 0;
		for (int j = 0; j < s0.length();)
		{
			if (s0[j] == '.')
			{
				scarecrow++;
				j += 3;
			}
			else
			{
				j++;
			}
		}

		cout << "Case " << i << ": " << scarecrow << '\n';
	}

	return 0;
}
