#include <iostream>
#include <string>
using namespace std;

// �r�����蹳: �`�N�ťզr�����ƥ�
string rev("A   3  HIL JM O   2TUVWXY51SE Z  8 ");

char mirrored(char ch); // �Ǧ^�r�����蹳

int main(void)
{
	string s;
	int p, m;
	int i;

	string meg[4] = {"not a palindrome",
					 "a regular palindrome",
					 "a mirrored string",
					 "a mirrored palindrome"};

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> s)
	{
		p = m = 1;

		for (i = 0; i < (double)s.length() / 2; i++)
		{ // �`�N�૬
			if (p && s[i] != s[(s.length() - 1) - i])
			{ // short-circuit
				p = 0;
			}
			if (m && mirrored(s[i]) != s[(s.length() - 1) - i])
			{
				m = 0;
			}
		}

		cout << s << " -- is " << meg[m * 2 + p] << ".\n\n";
	}

	return 0;
}

char mirrored(char ch) // �Ǧ^�r�����蹳
{
	if (isalpha(ch))
	{
		return rev[ch - 'A'];
	}
	else
	{
		return rev[ch - '0' + 25];
	}
}
