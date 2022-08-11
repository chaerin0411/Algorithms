#include <stdio.h>
#define DNUM 100

main() {
	int scores[DNUM], n, i, sum=0, over_count;
	double avg;

	printf("The number of data to be processed ");
	scanf("%d", &n);
	printf("Enter %d data : \n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &scores[i]);
		sum += scores[i];
	}
	avg = (double)sum / n;
	printf("Average = %.2f\n", avg);

	over_count = 0;
	for (i = 0; i < n; i++)
		if (scores[i] > avg) over_count++;
	printf("over average = %d\n", over_count);
}