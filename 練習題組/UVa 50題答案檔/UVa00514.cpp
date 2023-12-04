
#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	int target[1001];
	int n, i;
	int A, B;
	bool ok, first = true;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> n && n)
	{
		if (first)
			first = false;
		else
			cout << '\n';

		while (1)
		{
			stack<int> s; // block scope

			cin >> target[1];
			if (target[1] == 0)
				break;

			for (i = 2; i <= n; i++)
			{
				cin >> target[i];
			}

			A = B = 1;
			ok = true;
			while (B <= n)
			{
				if (A == target[B])
				{
					A++;
					B++;
				}
				else if (!s.empty() && s.top() == target[B])
				{
					s.pop();
					B++;
				}
				else if (A <= n)
				{
					s.push(A++);
				}
				else
				{
					ok = false;
					break;
				}
			}

			cout << (ok ? "Yes" : "No") << '\n';
		}
	}
	return 0;
}
