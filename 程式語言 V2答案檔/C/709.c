#include <stdio.h>
#include <stdlib.h>

struct Circle
{
	int x, y;
	int radius;
};

double compute(struct Circle *c[], int n, int *max);
int main()
{
	int num, i;
	int max = 0;
	scanf("%d", &num);
	struct Circle *c[num];
	for (i = 0; i < num; i++)
	{
		struct Circle *temp = (struct Circle *)malloc(sizeof(struct Circle));
		scanf("%d %d %d", &temp->x, &temp->y, &temp->radius);
		c[i] = temp;
	}

	double total = compute(c, num, &max);

	printf("Sum = %.2f\n", total);
	printf("x: %d, y: %d\n", c[max]->x, c[max]->y);
	printf("radius: %d\n", c[max]->radius);
	for (i = 0; i < num; i++)
		free(c[i]);
	return 0;
}

double compute(struct Circle *c[], int n, int *max)
{
	int i = 0;
	double sum = c[i]->radius * c[i]->radius * 3.14159;
	for (i = 1; i < n; i++)
	{
		if (c[*max]->radius < c[i]->radius)
		{
			*max = i;
		}
		sum += c[i]->radius * c[i]->radius * 3.14159;
	}
	return sum;
}
