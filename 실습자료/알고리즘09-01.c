// 0.00 - 99.99 사이의 실수 난수(random number)를 50개 만들어 배열 rdate에 저장하고 소수 부분의 합과 정수 부분의 합을 구하는 알고리즘을 작성하여 C프로그램으로 코딩하여 확인하시오. 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RNUM 50
#define random(n) rand() % n
main()
{
	float rdata[RNUM], fsum = 0.0;
	int i, isum = 0, temp;
	srand((unsigned int)time(NULL));
	for (i = 0; i < RNUM; i++) {
		rdata[i] = random(100) + random(100) / 100.0;
		printf("%6.2f ", rdata[i]);
		if ((i + 1) % 7 == 0) printf("\n");
	}
	for (i = 0; i < RNUM; i++) {
		temp = rdata[i];
		isum += temp;
		fsum += (rdata[i] - temp);
	}
	
	printf("\n\n정수부분의 합: %d\n", isum);
	printf("\n소수부분의 합: %.3f\n", fsum);
}