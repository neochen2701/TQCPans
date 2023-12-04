
#include <iostream>
#include <vector>
#include <algorithm> //for sort()
using namespace std;

int main(void)
{
	int w, h;
	bool possible;

	//==========================
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while (cin >> w >> h)
	{
		vector<pair<int, int>> box;
		box.push_back({min(w, h), max(w, h)}); // first �p�󵥩� second

		for (int i = 1; i < 6; i++)
		{
			cin >> w >> h;
			box.push_back({min(w, h), max(w, h)});
		}
		sort(box.begin(), box.end());

		possible = true;

		// ����: �����骺 6 �ӭ��@�w�O�i�H�Φ�3��ۦP���x��
		for (int i = 0; possible && i <= 4; i += 2)
		{
			if (box[i].first != box[i + 1].first || box[i].second != box[i + 1].second)
				possible = false;
		}

		// ����: �Ĥ@�ӵu��@�w����ĤT�Ӫ��u��
		if (possible && box[0].first != box[2].first)
			possible = false;

		// ����: �Ĥ@�Ӫ�����@�w����Ĥ��Ӫ��u��
		if (possible && box[0].second != box[4].first)
			possible = false;

		// ����: �ĤT�Ӫ�����@�w����Ĥ��Ӫ�����
		if (possible && box[2].second != box[4].second)
			possible = false;

		cout << (possible ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
	}

	return 0;
}
