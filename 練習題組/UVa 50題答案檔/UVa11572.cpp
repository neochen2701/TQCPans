
#include <iostream>
#include <set>
using namespace std;

int snow[1000000]; // �j�p���D�N

int main(void)
{
	int t, n;
	int L, R;
	int len;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> t;
	while (t--)
	{
		set<int> st;
		cin >> n;

		L = R = 0; //[L, R)
		len = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> snow[i];

			if (st.count(snow[i]))
			{ // ����
				len = max(len, R - L);

				do
				{
					st.erase(snow[L]);
				} while (snow[L++] != snow[i]);
			}

			st.insert(snow[i]);
			R++;
		}
		len = max(len, R - L);

		cout << len << '\n';
	}

	return 0;
}
