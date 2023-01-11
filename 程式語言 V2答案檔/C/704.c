#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, j, num=1, check;
	int a[15], b[15], c[15];
	scanf("%d", &n);
	
	for (i=0 ; i<n ; i++)
		scanf("%d", &a[i]);
	
	for (i=0 ; i<n ; i++)
		c[i] = 0;

	b[0] = a[0];

	for (i=0 ; i<n ; i++){
		check = 0;
		for (j=0 ; j<num ; j++){
			if (a[i] == b[j]){
				c[j] ++;
				check = 1;
				break;
			}
		}
		if (check == 0){
			b[num] = a[i];
			c[num]++;
			num++;
		}
	}
	
	check = 0;
	
	for (i=0 ; i<num ; i++){	
		if (c[i] > n/2){
			printf("%d\n", b[i]);
			check = 1;
		}
	}
	if (check == 0)
		printf("error\n"); 
	
	return 0;
}
