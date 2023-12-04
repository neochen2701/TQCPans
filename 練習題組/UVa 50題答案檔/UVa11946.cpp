
#include <iostream>
#include <map>
using namespace std;

void init(void);

map<char, char> code;

int main(void)
{
	int t;
	string s0;
	bool first = true;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	// �ت�
	init();

	getline(cin, s0);
	t = stoi(s0);

	while (t--)
	{
		if (first)
			first = false;
		else
			cout << '\n';

		while (getline(cin, s0))
		{
			if (s0.length() == 0)
				break;
			for (auto &c : s0)
			{
				if (code.count(c))
					c = code[c];
			}
			cout << s0 << '\n';
		}
	}

	return 0;
}

void init(void)
{
	string s0, s1;

	s0 = "H3LL0 MY L0V3, 1 M H499Y 83C4U53 500N 1 W1LL 83 70 Y0UR 51D3.";
	s1 = "HELLO MY LOVE, I M HAPPY BECAUSE SOON I WILL BE TO YOUR SIDE.";
	for (int i = 0; i < s0.length(); i++)
		s0[i] != s1[i] && (code[s0[i]] = s1[i]);

	s0 = "7H15 71M3 W17H0U7 Y0U H45 833N 373RN4L. 1 1NV173 Y0U 70 7H3 200";
	s1 = "THIS TIME WITHOUT YOU HAS BEEN ETERNAL. I INVITE YOU TO THE ZOO";
	for (int i = 0; i < s0.length(); i++)
		s0[i] != s1[i] && (code[s0[i]] = s1[i]);

	s0 = "0N3 70 533 7H3 238R45 4ND 60R1L45.";
	s1 = "ONE TO SEE THE ZEBRAS AND GORILAS.";
	for (int i = 0; i < s0.length(); i++)
		s0[i] != s1[i] && (code[s0[i]] = s1[i]);
}
