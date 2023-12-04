
#include <iostream>
#include <iomanip> //for setw()
using namespace std;

int a[20]; // �j�p���D�N(�P�h19�H, [0]����)
int n;

int go(int p, int d, int t);

int main(void)
{
	int k, m;
	int left;
	int pA, // for A
		pB; // for B

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> n >> k >> m && n)
	{
		for (int i = 1; i <= n; i++)
		{
			a[i] = i;
		}
		left = n; // left for �ѤU�H��
		pA = n;	  // �w�Ʀ�m(�h�^ 1 �B)
		pB = 1;

		while (left)
		{
			pA = go(pA, 1, k);	// 1 for �f�ɰw
			pB = go(pB, -1, m); //-1 for ���ɰw

			cout << setw(3) << pA;
			left--;
			if (pB != pA)
			{
				cout << setw(3) << pB;
				left--;
			}

			a[pA] = a[pB] = 0; // pA, pB ���}����

			if (left)
				cout << ',';
		}
		cout << '\n';
	}

	return 0;
}

int go(int p, int d, int t)
{
	while (t--)
	{
		do
		{
			p += d;
			p == (n + 1) && (p = 1);
			p == 0 && (p = n);
		} while (a[p] == 0); // 0 �����w���}����
	}
	return p;
}
