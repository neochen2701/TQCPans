
#include <iostream>
#include <sstream>
using namespace std;

int main(void)
{
	string s0;
	int t, f, kase = 0;
	char c;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	getline(cin, s0);
	t = stoi(s0);

	while (t--)
	{
		cout << "Case " << ++kase << ": ";
		getline(cin, s0);
		stringstream ss(s0);
		while (ss >> c >> f)
		{
			for (int i = 0; i < f; i++)
				cout << c;
		}
		cout << '\n';
	}

	return 0;
}
