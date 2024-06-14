#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n1, n2;

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n1 >> n2;
	vector<int> A(n1 + 1, 0), B(n2 + 1, 0);
	for (int i = 1; i <= n1; i++)
		cin >> A[i];
	for (int j = 1; j <= n2; j++)
		cin >> B[j];

	vector<int> DP(n2 + 1, 0);
	for (int i = 1; i <= n1; i++)
	{
		vector<int> temp(n2 + 1, 0);
		for (int j = 1; j <= n2; j++)
		{
			if (A[i] != B[j])
				temp[j] = max(temp[j - 1], DP[j]);
			else
				temp[j] = DP[j - 1] + 1;
		}
		DP = temp;
	}

	cout << DP[n2];

	return 0;
}
