
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	string strA, strB;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> strA)
	{
		cin >> strB;

		vector<int> vA(26, 0), vB(26, 0);

		for (auto c : strA)
			vA[c - 'A']++;
		for (auto c : strB)
			vB[c - 'A']++;

		sort(vA.begin(), vA.end());
		sort(vB.begin(), vB.end());

		cout << (vA == vB ? "YES" : "NO") << '\n';
	}

	return 0;
}
