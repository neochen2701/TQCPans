
#include <iostream>
#include <vector>
#include <algorithm> //for sort()
#include <map>
using namespace std;

string normalize(string s);

int main(void)
{
	string s0, s1;
	vector<string> words, ans;
	map<string, int> cnt;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> s0 && s0 != "#")
	{
		words.push_back(s0);
		s1 = normalize(s0);
		cnt[s1]++;
	}

	for (int i = 0; i < words.size(); i++)
	{
		if (cnt[normalize(words[i])] == 1)
		{
			ans.push_back(words[i]);
		}
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}

	return 0;
}

string normalize(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}

	sort(s.begin(), s.end());

	return s;
}
