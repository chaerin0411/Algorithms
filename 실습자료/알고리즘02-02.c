#include <stdio.h>
main()
{
	int i, data, n;
	float sum=0, avg=0;
	printf("평균성적을 구할 학생 수를 입력하시오 >> ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("학생의 성적을 입력하시오 >> ");
		scanf("%d", &data);
		sum += data;
	}
	avg = sum / n;
	printf("%d명 학생의 평균은 %.2f", n, avg);
}
