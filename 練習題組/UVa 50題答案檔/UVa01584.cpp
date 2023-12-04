#include <iostream>
#include <vector>
#include <algorithm> //for min_element()
using namespace std;

int main(void)
{
	int t;
	string s0;
	int len;
	vector<string> v;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> t;

	while (t--)
	{
		v.clear();
		cin >> s0;
		len = s0.length();

		s0 += s0;
		for (int i = 0; i < len; i++)
		{
			v.push_back(s0.substr(i, len));
		}

		cout << *min_element(v.begin(), v.end()) << '\n';
	}

	return 0;
}
