#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(void)
{
	int round;
	string s0, s1; // s0:���D�ѵ�, s2:�q��
	bool win, lose;
	int chance;
	int i;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> round)
	{
		if (round == -1)
			break;

		cin >> s0 >> s1;

		// �N�ѵ��r�� s0 ���r����i set (�@�˪��r���u�Ҽ{�@��)
		set<char> st0(s0.begin(), s0.end()); // block scope

		win = lose = false;
		chance = 7;
		set<char> st1; // �q�L���r��(block scope)

		for (i = 0; i < s1.length(); i++)
		{
			// �q�L���r�����A�Ҽ{
			if (st1.count(s1[i]))
				continue;
			st1.insert(s1[i]);

			if (st0.count(s1[i]))
			{
				st0.erase(s1[i]);
			}
			else
			{
				chance--;
			}

			if (!chance)
				lose = true;
			else if (st0.empty())
				win = true;

			if (win || lose)
				break;
		}

		cout << "Round " << round << '\n';
		if (win)
		{
			cout << "You win.\n";
		}
		else if (lose)
		{
			cout << "You lose.\n";
		}
		else
		{
			cout << "You chickened out.\n";
		}
	}

	return 0;
}
