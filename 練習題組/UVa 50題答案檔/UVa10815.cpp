
#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main(void)
{
	string s0, buf;
	set<string> dict;
	set<string>::iterator it;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> s0)
	{
		for (auto &c : s0)
		{
			if (isalpha(c))
				c = tolower(c); // �ন�p�g�r���r��
			else
				c = ' '; // �N�D�r���r���ন�ťզr��
		}

		stringstream ss(s0);
		while (ss >> buf)
		{
			dict.insert(buf);
		}
	}

	// �̦r��ǦC�X�Ҧ�����r
	for (it = dict.begin(); it != dict.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}
