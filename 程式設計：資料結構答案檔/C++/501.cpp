#include <iostream>
#include <fstream>
#include <cstring>

#define NEW2D(H, W, TYPE) (TYPE **)new2d(H, W, sizeof(TYPE))

using namespace std;

int **activities;
int num_activities = 0;

void *new2d(int h, int w, int size)
{
	int i;
	void **p;

	p = (void **)new int[h * sizeof(void *) + h * w * size];
	for (i = 0; i < h; i++)
		p[i] = ((int *)(p + h)) + i * w * size;

	return p;
}

void get_activity_from_input()
{
	activities = NEW2D(num_activities, 2, int);

	int row = 0;
	char buffer[256] = {0};
	char delim[] = ",";
	for (int i = 0; i < num_activities; i++)
	{
		cin >> buffer;

		char *token = strtok(buffer, delim);
		activities[row][0] = atoi(token);
		token = strtok(NULL, delim);
		activities[row][1] = atoi(token);
		row++;
	}
}

void sort_activities()
{
	for (int i = 0; i < num_activities - 1; i++)
	{
		for (int j = i + 1; j < num_activities; j++)
		{
			if (activities[i][1] > activities[j][1])
			{
				int *tmp = activities[i];
				activities[i] = activities[j];
				activities[j] = tmp;
			}
		}
	}
}

int main()
{
	cin >> num_activities;

	get_activity_from_input();
	sort_activities();

	int select = 1;
	int *curr_act = activities[0];
	for (int i = 1; i < num_activities; i++)
		if (curr_act[1] <= activities[i][0])
		{
			curr_act = activities[i];
			select++;
		}

	cout << select;

	delete[] activities;
	return 0;
}