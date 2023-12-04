#include <iostream>
using namespace std;

int c[1000000]; // �j�p���D�N, ���� cycle-length

int main(void)
{
	int i, j;
	int n, n0;
	int cycle;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> i >> j)
	{
		cycle = 1;

		for (n = min(i, j); n <= max(i, j); n++)
		{
			if (c[n] == 0)
			{ // cycle-length c[n]�|���Q�p��L
				n0 = n;

				// The 3n+1 algorithm
				while (1)
				{
					c[n]++;

					if (n0 == 1)
						break;

					if (n0 % 2)
					{
						n0 = 3 * n0 + 1;
					}
					else
					{
						n0 /= 2;
					}
				}
			}

			cycle = max(cycle, c[n]);
		}

		cout << i << " " << j << " " << cycle << '\n';
	}

	return 0;
}
