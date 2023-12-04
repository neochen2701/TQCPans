#include <iostream>
using namespace std;

int main(void)
{
	int n;
	int kase = 0;
	int i;
	int a[1000], b[1000]; // �}�C�j�p���D�N
	int A, B;
	int d, c1, c2;
	int m;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> n)
	{
		if (!n)
			break;

		cout << "Game " << ++kase << ":\n";

		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		while (1)
		{
			A = B = 0;

			for (i = 0; i < n; i++)
			{
				cin >> b[i];
				if (a[i] == b[i])
					A++; // �����έp�i�o A
			}

			m = 0;
			for (i = 0; i < n; i++)
			{
				if (b[i] == 0)
					m++;
			}
			if (m == n)
				break; // n �� '0'

			for (d = 1; d <= 9; d++)
			{ // �u�|�X�{�Ʀr 1 �� 9
				c1 = c2 = 0;

				// ��C�ӼƦr d,
				// �έp�X�{�b a �M  b ������: c1 �M c2
				for (i = 0; i < n; i++)
				{
					if (a[i] == d)
						c1++;
					if (b[i] == d)
						c2++;
				}
				// min(c1, c2)�N�O�Ʀr d �� B ���^�m
				B += min(c1, c2);
			}

			cout << "    " // ��X 4 �ťզr��
				 << '(' << A << ',' << B - A << ')' << '\n';
			// B-A: �̫�n��h A ������
		}
	}

	return 0;
}
