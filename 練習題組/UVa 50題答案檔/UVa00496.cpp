
#include <iostream>
#include <sstream>
#include <set>
using namespace std;

void classfy(set<int> &A, set<int> &B);

int main(void)
{
	string s;
	int element;
	bool first = true;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (getline(cin, s))
	{
		set<int> A, B, same;
		stringstream ssA(s);
		while (ssA >> element)
			A.insert(element);

		getline(cin, s);
		stringstream ssB(s);
		while (ssB >> element)
			B.insert(element);

		classfy(A, B);
	}

	return 0;
}

void classfy(set<int> &A, set<int> &B)
{
	set<int> same;

	for (auto i : A)
	{
		if (B.count(i))
		{
			same.insert(i);
			B.erase(i);
		}
	}
	for (auto i : same)
		A.erase(i);

	if (A.empty() && !B.empty())
	{
		cout << "A is a proper subset of B" << '\n';
	}
	else if (!A.empty() && B.empty())
	{
		cout << "B is a proper subset of A" << '\n';
	}
	else if (A.empty() && B.empty())
	{
		cout << "A equals B" << '\n';
	}
	else
	{
		if (same.size() == 0)
			cout << "A and B are disjoint" << '\n';
		else
			cout << "I'm confused!" << '\n';
	}
}
