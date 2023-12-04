
#include <iostream>
using namespace std;

int main(void)
{
	int n, D, I;
	int depth;
	int k;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> n;

	while (n--)
	{
		cin >> D >> I;
		k = 1; // �`�I�s��
		for (depth = 1; depth < D; depth++)
		{
			if (I % 2)
			{ // �_�ƦV��
				k = k * 2;
				I = (I + 1) / 2; // �U�@�h���ĴX�ө_��
			}
			else
			{ // ���ƦV�k
				k = k * 2 + 1;
				I = I / 2; // �U�@�h���ĴX�Ӱ���
			}
		}
		cout << k << '\n';
	}

	return 0;
}
