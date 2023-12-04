
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void)
{
	int t, n, step;
	bool zero;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<int> v0(n), v1(n);

		set<vector<int>> st;

		for (int i = 0; i < n; i++)
			cin >> v0[i];
		st.insert(v0);
		zero = false;
		step = 0;

		while (++step <= 1000)
		{
			if (v0 == vector<int>(n))
			{
				zero = true;
				break;
			}

			for (int i = 0; i < n; i++)
			{
				v1[i] = abs(v0[i] - v0[(i + 1) % n]);
			}
			v0 = v1;

			if (st.count(v0))
				break;
			else
				st.insert(v0);
		}

		if (zero)
			cout << "ZERO" << '\n';
		else
			cout << "LOOP" << '\n';
	}

	return 0;
}
