// 0.00 - 99.99 ������ �Ǽ� ����(random number)�� 50�� ����� �迭 rdate�� �����ϰ� �Ҽ� �κ��� �հ� ���� �κ��� ���� ���ϴ� �˰����� �ۼ��Ͽ� C���α׷����� �ڵ��Ͽ� Ȯ���Ͻÿ�. 
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
	
	printf("\n\n�����κ��� ��: %d\n", isum);
	printf("\n�Ҽ��κ��� ��: %.3f\n", fsum);
}