
#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	int n, kase = 0;
	string s0;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> n;
	while (n--)
	{
		cin >> s0;
		set<int> st;

		cout << "Case #" << ++kase << ": " << s0 << " ";

		while (1)
		{
			int num = 0;
			for (auto c : s0)
				num += (c - '0') * (c - '0');

			if (num == 1)
			{
				cout << "is a Happy number." << '\n';
				break;
			}

			if (st.count(num))
			{
				cout << "is an Unhappy number." << '\n';
				break;
			}

			st.insert(num);
			s0 = to_string(num);
		}
	}

	return 0;
}
