
#include <iostream>
#include <algorithm> //for reverse()
using namespace std;

int main(void)
{
	int n, g;
	string s0, s1;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> n && n)
	{
		cin >> s0;
		g = s0.length() / n;
		for (int i = 0; i < s0.length(); i += g)
		{
			s1 = s0.substr(i, g);
			reverse(s1.begin(), s1.end());
			cout << s1;
		}
		cout << '\n';
	}

	return 0;
}
