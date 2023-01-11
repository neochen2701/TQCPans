#include <stdio.h>
#include <stdlib.h>

typedef struct rectangle {
	int height;
	int width;
	int area;
} Rect;

int compute(const void * rect1, const void * rect2);

int main() {
	int N, i;
	Rect *rect_arr;

	scanf("%d", &N);
	rect_arr = (Rect *) malloc(sizeof(Rect) * N);

	// input N rectangles
	for (i = 0; i < N; i++) {
		scanf("%d %d", &rect_arr[i].height, &rect_arr[i].width);
		rect_arr[i].area = rect_arr[i].height * rect_arr[i].width;
	}

	// sort rect_arr
	qsort(rect_arr, N, sizeof(Rect), compute);

	// output areas for each rectangle
	for (i = 0; i < N; i++) {
		printf("%dx%d=%d",
			rect_arr[i].height, rect_arr[i].width, rect_arr[i].area);

		if (i < N - 1) {
			printf("\n");
		}
	}

	free(rect_arr);

	return 0;
}

int compute(const void * rect1, const void * rect2) {
	return ((Rect *) rect1)->area - ((Rect *) rect2)->area;
}

