#include <stdio.h>
main()
{
	int i, data, n;
	float sum=0, avg=0;
	printf("��ռ����� ���� �л� ���� �Է��Ͻÿ� >> ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("�л��� ������ �Է��Ͻÿ� >> ");
		scanf("%d", &data);
		sum += data;
	}
	avg = sum / n;
	printf("%d�� �л��� ����� %.2f", n, avg);
}
