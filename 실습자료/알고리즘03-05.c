#include <stdio.h>
#define NUM 30
double find_avg(int sdata[][2], int n);
int find_max(int sdata[][2], int n);
int find_rank(int sdata[][2], int n);

main()
{
	int i, scores[NUM][2], sid, n;
	printf("Enter n : ");
	scanf("%d", &n);
	printf("Input id and score : \n");
	for (i = 0; i < n; i++) {
		scanf("%d %d", &scores[i][0], &scores[i][1]);
	}
	printf("��� = %.2f\n", find_avg(scores, n));
	printf("�ִ밪 = %d\n", find_max(scores, n));

	printf("Input id to be search : ");
	scanf("%d", &sid);
	printf("%d���� ��� : %d\n", sid, find_rank(scores, n, sid));
}

double find_avg(int sdata[][2], int n)
{
	int i;
	double avg = 0;
	for (int i = 0; i < n; i++) {
		avg += sdata[i][1];
	}
	avg = avg / n;
	return avg;
}

int find_max(int sdata[][2], int n)
{
	int i, max;
	max = sdata[0][1];
	for (i = 1; i < n; i++) {
		if (sdata[i][1] > max) max = sdata[i][1];
	}
	return max;
}

int find_rank(int sdata[][2], int n, int sid)
{
	int i, jumsu, rank;

	for (i = 0; i < n; i++) {
		if (sid == sdata[i][0]) {
			jumsu = sdata[i][1];
			break;
		}
	}

	rank = 0;
	for (i = 0; i < n; i++) {
			if (sdata[i][1] > jumsu) rank++;
	}
	return rank + 1;
}