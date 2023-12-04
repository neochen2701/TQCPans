#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	// �`�N�r��`�Ƥ���k�r�� '\' ���g�k '\\'
	string s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char c;
	int i;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin.get(c))
	{
		for (i = 1; i < s.length() && s[i] != c; i++)
			;

		if (i < s.length())
		{
			cout << s[i - 1];
		}
		else
		{
			cout << c;
		}
	}

	return 0;
}
