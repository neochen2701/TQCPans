
#include <iostream>
#include <vector>
#include <algorithm> //for __gcd()
using namespace std;

int main(void)
{
	int T;
	int n, k, f, GCD, time;
	string m;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> T;
	while (T--)
	{
		vector<pair<string, int>> v;

		cin >> n >> k;
		while (n--)
		{
			cin >> m >> f;
			v.push_back({m, f}); // �ĦW vs. �W�v
		}

		GCD = v[0].second;
		for (int i = 1; i < v.size(); i++)
		{
			GCD = __gcd(GCD, v[i].second);
		}

		time = GCD; // �̤p�ɶ����
		while (k)
		{
			for (auto p : v)
			{
				if (time % p.second == 0)
				{
					cout << time << " " << p.first << '\n';
					if (--k == 0)
						break;
				}
			}
			time += GCD;
		}
	}

	return 0;
}
