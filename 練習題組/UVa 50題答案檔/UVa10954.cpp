
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int n;
	int i, d;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> n && n)
	{
		priority_queue<int, vector<int>, greater<int>> pq;
		for (i = 0; i < n; i++)
		{
			cin >> d;
			pq.push(d);
		}

		long long sum, cost = 0;
		while (pq.size() != 1)
		{
			sum = pq.top();
			pq.pop();
			sum += pq.top();
			pq.pop();

			cost += sum;
			pq.push(sum);
		}

		cout << cost << '\n';
	}

	return 0;
}
