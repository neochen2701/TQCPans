
#include <iostream>
#include <vector>
#include <iomanip> //for setw()
using namespace std;

void init(void);
int freq(int n, int p);

vector<int> prime;

int main(void)
{
	int n;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	init();

	while (cin >> n)
	{
		if (n == 0)
			break;

		vector<int> seq;
		for (auto p : prime)
		{
			if (p > n)
				break;

			seq.push_back(freq(n, p));
		}

		cout << setw(3) << n << "! =";

		int pos = 1;
		for (auto e : seq)
		{
			if (pos == 16)
			{
				cout << '\n'
					 << setw(6) << "";
				pos = 1;
			}
			cout << setw(3) << e;
			pos++;
		}
		cout << '\n';
	}

	return 0;
}

// ���D�N�O�� 100 �H�U�����
void init(void)
{
	int factor = 2;
	bool isPrime;

	while (factor <= 100)
	{
		isPrime = true;

		for (int i = 0; i < prime.size(); i++)
		{
			if (factor < prime[i] * prime[i])
			{
				break;
			}
			if (factor % prime[i] == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			prime.push_back(factor);

		factor++;
	}
}

int freq(int n, int p)
{
	int exp = 0;

	do
	{
		exp += n / p;
		n /= p;
	} while (n > 1);

	return exp;
}
