
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int kase;
	int m, n;
	string s0;
	int distance = 0;
	int a, c, g, t;

	char target;
	int count;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> kase;
	while (kase--)
	{
		vector<string> DNA;

		cin >> m >> n; // m sequences of length n
		while (m--)
		{
			cin >> s0;
			DNA.push_back(s0);
		}

		distance = 0;
		for (int i = 0; i < n; i++)
		{
			a = c = g = t = 0;
			for (int j = 0; j < DNA.size(); j++)
			{
				if (DNA[j][i] == 'A')
					a++;
				else if (DNA[j][i] == 'C')
					c++;
				else if (DNA[j][i] == 'G')
					g++;
				else
					t++; //'T'
			}

			target = 'A';
			count = a;
			if (c > count)
			{
				count = c;
				target = 'C';
			}
			if (g > count)
			{
				count = g;
				target = 'G';
			}
			if (t > count)
			{
				count = t;
				target = 'T';
			}

			cout << target;
			distance += DNA.size() - count;
		}
		cout << '\n'
			 << distance << '\n';
	}

	return 0;
}
