#include <iostream>
using namespace std;

int build(void);
int decode(int w);

char code[8][128]; //[����][�X]

int main(void)
{
	int len, index;
	string s0;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (build())
	{
		while (1)
		{
			len = decode(3);
			if (len == 0)
				break;

			while (1)
			{
				index = decode(len);
				if (index == (1 << len) - 1)
					break;
				cout << code[len][index];
			}
		}
		cout << '\n';
		getline(cin, s0); // �h������r��
	}

	return 0;
}

// �إ߸ѽX��
int build(void)
{
	string s0;
	string::iterator it;

	if (!getline(cin, s0))
		return 0;

	it = s0.begin();
	for (int i = 1; it != s0.end() && i <= 7; i++)
	{ // ���ץ� 1 �}�l
		for (int j = 0; it != s0.end() && j < (1 << i) - 1; j++)
		{
			code[i][j] = *it++;
		}
	}

	return 1;
}

// �ѽX
int decode(int w)
{
	int value = 0;
	char c;

	while (w--)
	{
		cin >> c;
		value = value * 2 + c - '0';
	}

	return value;
}
