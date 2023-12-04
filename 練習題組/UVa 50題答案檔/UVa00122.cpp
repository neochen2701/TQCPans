
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void levelize(vector<string> &v);

int main(void)
{
	string s0;
	vector<string> v;
	bool first = true;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> s0)
	{
		v.push_back(s0);
		while (cin >> s0)
		{
			if (s0 == "()")
				break;
			v.push_back(s0);
		}

		if (first)
			first = false;
		else
			cout << '\n';

		levelize(v);

		v.clear();
	}

	return 0;
}

void levelize(vector<string> &v)
{
	int pos, val, index;
	string path;
	map<int, int> st;
	bool valid = true, first = true;

	for (auto s : v)
	{
		pos = s.find(',');
		val = stoi(s.substr(1, pos - 1));
		path = s.substr(pos + 1, s.length() - (pos + 1) - 1);

		index = 0;
		for (auto c : path)
		{
			if (c == 'L')
				index = index * 2 + 1;
			else
				index = index * 2 + 2; //'R'
		}

		if (!st.count(index))
		{
			st[index] = val; // sorted by index (levelize)
		}
		else
		{ // ����
			valid = false;
			break;
		}
	}

	if (valid)
	{
		for (auto node : st)
		{
			if (!st.count((node.first - 1) / 2))
			{
				valid = false;
				break;
			}
		}
	}

	if (valid)
	{
		for (auto node : st)
		{
			if (first)
				first = false;
			else
				cout << ' ';
			cout << node.second;
		}
	}
	else
	{
		cout << "not complete";
	}
}
