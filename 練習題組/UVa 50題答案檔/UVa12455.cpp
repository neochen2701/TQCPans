
#include <iostream>
#include <vector>
using namespace std;

int L[21];				  // �j�p���D�N
int DP[1001], temp[1001]; // �j�p���D�N

int main(void)
{
	int t;
	int n, p;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> t;
	while (t--)
	{
		cin >> n >> p;
		for (int i = 1; i <= p; i++)
		{ //[0]����
			cin >> L[i];
		}

		// �ʺA�W��(Dynamic Programming, DP): �̨Τ�
		vector<int> DP(n + 1, 0);
		for (int i = 1; i <= p; i++)
		{
			vector<int> temp(n + 1, 0);

			for (int j = 1; j <= n; j++)
			{
				if (j - L[i] < 0)
					temp[j] = DP[j];
				else
					temp[j] = max(DP[j], L[i] + DP[j - L[i]]);
			}

			DP = temp;
		}

		cout << (DP[n] == n ? "YES" : "NO") << '\n';
	}

	return 0;
}
