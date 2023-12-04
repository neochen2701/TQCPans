
#include <iostream>
#include <vector>
#include <algorithm> //for sort()
using namespace std;

struct Task
{
	int id, d, p; // ID, Days, Penalty
};

void sol(void);
bool comp(Task a, Task b);

int main(void)
{
	int t;
	bool first = true;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	cin >> t;
	while (t--)
	{
		if (first)
			first = false;
		else
			cout << "\n\n";

		sol();
	}

	return 0;
}

void sol(void)
{
	int n;
	int d, p;
	bool first = true;

	cin >> n;
	vector<Task> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> d >> p;
		v[i] = Task{i + 1, d, p}; // �s���q 1 �}�l
	}

	sort(v.begin(), v.end(), comp);

	for (auto t : v)
	{
		if (first)
			first = false;
		else
			cout << ' ';

		cout << t.id;
	}
}

bool comp(Task a, Task b)
{
	if (a.p * b.d > b.p * a.d)
		return true;

	if (a.p * b.d == b.p * a.d && a.id < b.id)
		return true;

	return false;
}
