
#include <iostream>
#include <vector>
using namespace std;

void find_block(int a, int &pa, int &ha);
void clear_above(int p, int h);
void pipe_over(int p0, int h0, int p1);
void show(void);

int n;
vector<int> pipe[25]; // �j�p���D�N

int main(void)
{
	int i;
	string s1, s2;
	int a, b;
	int pa, pb; // pa, pb: positions of a and b
	int ha, hb; // ha, hb: heights of a and b

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> n;
	for (i = 0; i < n; i++)
	{
		pipe[i].push_back(i);
	}

	while (1)
	{
		cin >> s1;
		if (s1 == "quit")
			break;

		cin >> a >> s2 >> b;
		find_block(a, pa, ha);
		find_block(b, pb, hb);

		if (pa == pb)
			continue; // �D�k���O

		if (s1 == "move")
			clear_above(pa, ha);
		if (s2 == "onto")
			clear_above(pb, hb);
		pipe_over(pa, ha, pb);
	}
	show();

	return 0;
}

// �o�{��� a ����m p �M���� h (�ұq 0 ��_)
void find_block(int a, int &p, int &h)
{
	for (p = 0; p < n; p++)
	{
		for (h = 0; h < pipe[p].size(); h++)
		{
			if (pipe[p][h] == a)
				return;
		}
	}
}

// ����w���"�W�誺"�Ҧ�����k��
void clear_above(int p, int h)
{
	for (int i = pipe[p].size() - 1; i > h; i--)
	{
		pipe[pipe[p][i]].push_back(pipe[p][i]);
		pipe[p].pop_back();
	}
}

// ����w����s�P�W�誺�Ҧ�����T����w�B p1
void pipe_over(int p0, int h0, int p1)
{
	pipe[p1].insert(pipe[p1].end(), pipe[p0].begin() + h0, pipe[p0].end());
	pipe[p0].erase(pipe[p0].begin() + h0, pipe[p0].end());
}

// ��X���G
void show(void)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		cout << i << ":";
		for (j = 0; j < pipe[i].size(); j++)
		{
			cout << " " << pipe[i][j];
		}
		cout << '\n';
	}
}
