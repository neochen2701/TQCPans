
#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main(void)
{
	int t, n, x;
	int i;
	int t0;
	int kase = 0;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> t && t)
	{						// t: the number of teams, 0 for quit
		map<int, int> team; // block scope
		for (i = 0; i < t; i++)
		{
			cin >> n; // n: the number of elements of team i
			while (n--)
			{
				cin >> x; // x: element
				team[x] = i;
			}
		}

		queue<int> teamQueue;

		queue<int> elementQueue[1000];
		// elemnetQueue[i]: queue of elements of team i

		cout << "Scenario #" << ++kase << '\n';
		while (1)
		{
			string cmd; // block scope
			cin >> cmd;

			if (cmd == "STOP")
			{ // STOP
				break;
			}
			else if (cmd == "DEQUEUE")
			{ // DEQUEUE
				t0 = teamQueue.front();
				cout << elementQueue[t0].front() << '\n';
				elementQueue[t0].pop();
				if (elementQueue[t0].empty())
				{
					teamQueue.pop();
				}
			}
			else if (cmd == "ENQUEUE")
			{ // ENQUEUE
				cin >> x;
				t0 = team[x];
				if (elementQueue[t0].empty())
				{
					teamQueue.push(t0);
				}
				elementQueue[t0].push(x);
			}
		}
		cout << '\n';
	}

	return 0;
}
