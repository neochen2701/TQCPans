#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	int n, v, threshold;
	int v0, v1, w;
	queue<pair<int, int>> q;
	int ans = 0;

	cin >> n >> v >> threshold;
	bool visited[n + 1] = {};
	vector<pair<int, int>> node[n + 1];

	for (int i = 0; i < n - 1; i++)
	{
		cin >> v0 >> v1 >> w;
		node[v0].push_back({v1, w});
		node[v1].push_back({v0, w});
	}

	visited[v] = true;
	q.push({v, 2147483647});
	while (!q.empty())
	{
		pair<int, int> t = q.front();
		q.pop();

		for (auto p : node[t.first])
		{
			if (visited[p.first])
				continue;

			visited[p.first] = true;
			if (min(t.second, p.second) >= threshold)
			{
				ans++;
				q.push({p.first, min(t.second, p.second)});
			}
		}
	}
	cout << ans;

	return 0;
}
