#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[128], *pch;
    int num = 0, sum = 0;

    cin >> input;
	pch = strtok(input, "/");
	while (pch != NULL) {
		num = atoi(pch);
		sum += num;
		cout << num;

		pch = strtok(NULL, "/");
		if (pch != NULL) {
			cout << " ";
		}
		else {
			cout << endl;
		}
	}
	cout << sum;
    return (0);
}