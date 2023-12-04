#include <iostream>
using namespace std;

// �g���վ��@�P�� 4, [0] �N�� 4k ���� (k ���� 0)
int t[10][4] = {
	{},			  // 0�����ƴ`�� (�Τ���)
	{1, 1, 1, 1}, // 1�����ƴ`��
	{6, 2, 4, 8}, // 2�����ƴ`��
	{1, 3, 9, 7}, // 3�����ƴ`��
	{6, 4, 6, 4}, // 4�����ƴ`��
	{5, 5, 5, 5}, // 5�����ƴ`��
	{6, 6, 6, 6}, // 6�����ƴ`��
	{1, 7, 9, 3}, // 7�����ƴ`��
	{6, 8, 4, 2}, // 8�����ƴ`��
	{1, 9, 1, 9}  // 9�����ƴ`��
};

int main(void)
{
	string strM, strN;
	int m, n;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> strM >> strN)
	{
		if (strM == "0" && strN == "0")
			break;

		m = strM.back() - '0';

		if (strN.length() >= 2)
		{
			n = stoi(strN.substr(strN.length() - 2, 2));
		}
		else
		{
			n = stoi(strN.substr(strN.length() - 1, 1));
		}

		if (m == 0)
			cout << 0 << '\n'; // 0 �����󦸤�O 0
		else if (n == 0)
			cout << 1 << '\n'; // �D 0 �����󦸤�O 1
		else
			cout << t[m][n % 4] << '\n';
	}

	return 0;
}
