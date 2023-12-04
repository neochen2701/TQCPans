
#include <iostream>
using namespace std;

int main(void)
{
	int state[31][4];
	// ���� vs. �̫�s�� U ����(0, 1, 2�w��; 3 ���w��)
	int n;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	state[0][0] = 1;
	state[0][1] = state[0][2] = state[0][3] = 0;

	for (int h = 1; h <= 30; h++)
	{
		// safe
		state[h][0] = state[h - 1][0] + state[h - 1][1] + state[h - 1][2];
		state[h][1] = state[h - 1][0];
		state[h][2] = state[h - 1][1];

		// unsafe
		state[h][3] = state[h - 1][2] + state[h - 1][3] * 2;
	}

	while (cin >> n && n)
		cout << state[n][3] << '\n';

	return 0;
}
