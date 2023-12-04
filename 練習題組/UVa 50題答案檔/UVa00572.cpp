#include <iostream>
#include <vector>
#include <cstring> //for memset()
using namespace std;

void recur_dfs(int r, int c, int id);

vector<string> pic;
int idx[100][100]; // 0 for non-visited, 1 for visited,
int m, n;

int main(void)
{
	int i, j;
	string s0;
	int count;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> m >> n)
	{
		if (m == 0)
			break;

		pic.clear();
		count = 0;
		memset(idx, 0, sizeof(idx));

		for (i = 0; i < m; i++)
		{
			cin >> s0;
			pic.push_back(s0);
		}

		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (idx[i][j] == 0 && pic[i][j] == '@')
				{
					recur_dfs(i, j, ++count);
				}
			}
		}

		cout << count << '\n';
	}

	return 0;
}

// ��Xpic[r][c]���ݪ��p�q��
void recur_dfs(int r, int c, int id)
{
	int dr, dc;
	int R, C;

	idx[r][c] = id;

	for (dr = -1; dr <= 1; dr++)
	{
		for (dc = -1; dc <= 1; dc++)
		{
			if (dr != 0 || dc != 0)
			{
				R = r + dr;
				C = c + dc;
				if ((0 <= R && R < m) && (0 <= C && C < n) && idx[R][C] == 0 && pic[R][C] == '@')
				{
					recur_dfs(R, C, id);
				}
			}
		}
	}
}
