
#include <iostream>
#include <vector>
using namespace std;

#define N 10000 // �j�p���D�N

int main(void)
{
	int Z, I, M, L;
	int kase = 0;
	bool first = true;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> Z >> I >> M >> L)
	{
		if (Z + I + M + L == 0)
			break;
		vector<int> pr(N, 0); // value, idx
		int idx = 0;

		if (first)
			first = false;
		else
			cout << '\n';
		cout << "Case " << ++kase << ": ";

		while (1)
		{
			if (pr[L])
			{
				cout << idx - pr[L];
				break;
			}
			pr[L] = idx++;
			L = (Z * L + I) % M;
		}
	}

	return 0;
}
