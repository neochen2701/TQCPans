
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm> //set_union(), set_intersection()
#include <iterator>	 //inserter()
using namespace std;

typedef set<int> Set;
map<Set, int> IdCache; // Set -> ID
vector<Set> SetCache;  // ID -> Set

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

int ID(Set x);

int main(void)
{
	int T, n;
	stack<int> s; // SetID

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> T;
	while (T--)
	{
		cin >> n;
		while (n--)
		{
			string op; // block scope
			cin >> op;

			if (op[0] == 'P')
			{		   // PUSH
				Set x; // block scope
				s.push(ID(x));
			}
			else if (op[0] == 'D')
			{ // DUP
				s.push(s.top());
			}
			else
			{
				Set x1, x2, x; // block scope
				x1 = SetCache[s.top()];
				s.pop();
				x2 = SetCache[s.top()];
				s.pop();

				if (op[0] == 'U')
				{ // UNION
					set_union(ALL(x1), ALL(x2), INS(x));
				}
				else if (op[0] == 'I')
				{ // INTERSECT
					set_intersection(ALL(x1), ALL(x2), INS(x));
				}
				else
				{ // ADD
					x = x2;
					x.insert(ID(x1));
				}

				s.push(ID(x));
			}
			cout << SetCache[s.top()].size() << '\n';
		}
		cout << "***" << '\n';
	}

	return 0;
}

int ID(Set x)
{
	if (IdCache.count(x))
	{
		return IdCache[x];
	}
	SetCache.push_back(x);

	return IdCache[x] = SetCache.size() - 1;
}
