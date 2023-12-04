
#include <iostream>
using namespace std;

int main(void)
{
	int n;
	string s0;
	int a[16]; // �d����16�ӼƦr
	int sum0, sum1;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> n;
	while (n--)
	{
		for (int i = 0; i < 4; i++)
		{
			cin >> s0;
			for (int j = 0; j < 4; j++)
			{
				a[i * 4 + j] = s0[j] - '0';
			}
		}

		// P.s. �̥���O�̫�@��
		sum0 = sum1 = 0;
		for (int i = 0; i < 16; i++)
		{
			if (i % 2)
			{ // �q�˼ƲĤG�Ӧ줸�}�l�A�N�L�̩��᭱ (�Ʀr�[�`)
				sum1 += a[i];
			}
			else
			{ // �[����L�S�����ʪ��Ʀr (�Ʀr�[�`)
				a[i] *= 2;
				sum0 += (a[i] / 10 + a[i] % 10); // �Ʀr�M
			}
		}

		cout << ((sum0 + sum1) % 10 ? "Invalid" : "Valid") << '\n';
	}

	return 0;
}
