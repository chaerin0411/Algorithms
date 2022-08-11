#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RNUM 50
#define random(n) rand() % n

void selection_sort(float a[], int n);
main(int argc, char* argv[])
{
	float rdata[RNUM], fsum = 0.0;
	int i, isum = 0, temp;
	FILE* out;

	if (argc != 2) {
		printf("실행인수를 잘못 주었습니다...\n");
		exit(1);
	}
	if ((out = fopen(argv[1], "w")) == NULL) {
		printf("출력파일을 생성할 수 없습니다\n");
		exit(1);
	}
	srand((unsigned int)time(NULL));
	for (i = 0; i < RNUM; i++) {
		rdata[i] = random(100) + random(100)/100.0;
		printf("%6.2f ", rdata[i]);
		if ((i + 1) % 7 == 0) printf("\n");
	}
	for (i = 0; i < RNUM; i++) {
		temp = rdata[i];
		isum += temp;
		fsum += (rdata[i] - temp);
	}
	printf("\n\n: %d\n", isum);
	printf("\n: %.3f\n", fsum);

	selection_sort(rdata, RNUM);
	for (i = 0; i < RNUM; i++) {
		fprintf(out, "%6.2f", rdata[i]);
		if ((i + 1) % 7 == 0) fprintf(out, "\n");
	}
}

void selection_sort(float a[], int n) {
	int s, m, j;
	float temp;
	for (s = 0; s < n - 1; s++) {
		m = s;
		for (j = s + 1; j < n; j++) {
			if (a[j] < a[m]) m = j;
		}
		temp = a[s];
		a[s] = a[m];
		a[m] = temp;
	} /* for */
} /* sort */

