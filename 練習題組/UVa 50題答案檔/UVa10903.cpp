
#include <iostream>
#include <map>
#include <vector>
#include <iomanip> //for setprecision()
using namespace std;
void init(void);

map<pair<string, string>, int> st;

int main(void)
{
	int n, k, count;
	;
	int id0, id1;
	string s0, s1;
	bool first = true;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cout << fixed;

	init();

	while (cin >> n && n)
	{
		vector<int> win(n + 1), lose(n + 1); //[0]����

		cin >> k;
		count = k * n * (n - 1) / 2;
		while (count--)
		{
			cin >> id0 >> s0 >> id1 >> s1;
			if (st[{s0, s1}] == 1)
			{
				win[id0]++;
				lose[id1]++;
			}
			else if (st[{s0, s1}] == -1)
			{
				lose[id0]++;
				win[id1]++;
			}
		}

		if (first)
			first = false;
		else
			cout << '\n';

		for (int i = 1; i <= n; i++)
		{
			if (win[i] + lose[i] == 0)
				cout << '-' << '\n';
			else
				cout << setprecision(3) << (double)win[i] / (win[i] + lose[i]) << '\n';
		}
	}

	return 0;
}

void init(void)
{
	//"rock" for ���Y
	//"scissors" for �ŤM
	//"paper" for ��

	st[{"rock", "rock"}] = 0;
	st[{"rock", "scissors"}] = 1;
	st[{"rock", "paper"}] = -1;

	st[{"scissors", "scissors"}] = 0;
	st[{"scissors", "paper"}] = 1;
	st[{"scissors", "rock"}] = -1;

	st[{"paper", "paper"}] = 0;
	st[{"paper", "rock"}] = 1;
	st[{"paper", "scissors"}] = -1;
}
