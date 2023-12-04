
#include <iostream>
#include <vector>
#include <algorithm> //for sort()
using namespace std;

int main(void)
{
	int p, n;
	int CA; // color(>0 for blue; <0 for red) & area
	int level, color;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> p;
	while (p--)
	{
		vector<pair<int, int>> board;

		cin >> n;

		if (n == 0)
		{
			cout << 0 << '\n';
			continue;
		}

		for (int i = 0; i < n; i++)
		{
			cin >> CA;
			if (CA > 0)
				board.push_back({CA, 1}); // blue
			else
				board.push_back({-CA, -1}); // red
		}

		// Greedy Algorithm (�g�ߺt��k)
		sort(board.begin(), board.end()); // �Ѥp��j

		// Hints: �S�������ӼӼh�����n�ۦP
		level = 1;
		color = board[n - 1].second; // �j�����Q�Ҽ{
		for (int i = n - 2; i >= 0; i--)
		{
			if (color == board[i].second)
				continue;
			else
			{
				level++;
				color = board[i].second;
			}
		}

		cout << level << '\n';
	}

	return 0;
}
