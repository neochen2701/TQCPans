
#include <iostream>
#include <vector>
#include <algorithm> //for lower_bound()
using namespace std;

int main(void)
{
	int kase = 0;
	int N, Q;
	int num;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> N >> Q)
	{
		if (N == 0)
			break;

		vector<int> a; // block scope
		vector<int>::iterator it;

		while (N--)
		{
			cin >> num;
			a.push_back(num);
		}
		sort(a.begin(), a.end());

		cout << "CASE# " << ++kase << ":"
			 << "\n";
		while (Q--)
		{
			cin >> num;

			it = lower_bound(a.begin(), a.end(), num);
			if (it != a.end() && *it == num)
			{
				cout << num << " found at " << it - a.begin() + 1 << '\n';
			}
			else
			{
				cout << num << " not found" << '\n';
			}
		}
	}

	return 0;
}
